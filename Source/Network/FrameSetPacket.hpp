#include <Network/Packet.cpp>
#include <Other/Int24.hpp>
#include <vector>
#include <Json.hpp>

using nlohmann::json;
using std::vector;

class FrameSetPacket
{
    Packet packet;
    json data;

    void decodePacket()
    {
        data.clear();
        short pointOfRead;
        short packetSize = packet.getSize();
        data["SequenceNumber"] = this->packet.readUInt24(pointOfRead).toUInt32();
        pointOfRead += 3;
        data["Frames"] = json::array();
        char frameNumber = 0;
        while (pointOfRead != packetSize)
        {
            data["Frames"].push_back(json::object());
            data["Frames"][frameNumber]["Flags"] = packet[pointOfRead];
            ++pointOfRead;
            data["Frames"][frameNumber]["Length"] = packet.readUInt16(pointOfRead);
            pointOfRead += 2;
            data["Frames"][frameNumber]["ReliableFrameIndex"] = this->packet.readUInt24(pointOfRead).toUInt32();
            pointOfRead += 3;
            data["Frames"][frameNumber]["SequencedFrameIndex"] = this->packet.readUInt24(pointOfRead).toUInt32();
            pointOfRead += 3;
            data["Frames"][frameNumber]["Order"] = json::object();
            data["Frames"][frameNumber]["Order"]["OrderedFrameIndex"] = this->packet.readUInt24(pointOfRead).toUInt32();
            pointOfRead += 3;
            data["Frames"][frameNumber]["Order"]["OrderChannel"] = packet[pointOfRead];
            ++pointOfRead;
            data["Frames"][frameNumber]["Fragment"] = json::object();
            data["Frames"][frameNumber]["Fragment"]["CompoundSize"] = this->packet.readInt32(pointOfRead);
            pointOfRead += 4;
            data["Frames"][frameNumber]["Fragment"]["CompoundID"] = this->packet.readInt16(pointOfRead);
            pointOfRead += 2;
            data["Frames"][frameNumber]["Fragment"]["Index"] = this->packet.readInt32(pointOfRead);
            pointOfRead += 4;
            data["Frames"][frameNumber]["Body"] = json::array();
            short bodySize = data["Frames"][frameNumber]["Length"]/8;
            for(short i = 0; i < bodySize; ++i) {
                data["Frames"][frameNumber]["Body"][i] = packet[pointOfRead];
                ++pointOfRead;
            }
            ++frameNumber;
        }
    }

public:
    FrameSetPacket(char *buffer, short size) : packet(Packet{buffer, size})
    {
        decodePacket();
    }
    FrameSetPacket(Packet packet) : packet(packet)
    {
        decodePacket();
    }
    Packet getPacket()
    {
        return this->packet;
    }
    json getData() {
        return this-data;
    }
};