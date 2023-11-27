#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include <assert.h>

enum class PacketType : int8_t
{
    INTERFACE = -1,
    INTEGER = 0,
    LIST = 1
};



class Packet
{
    public:
        virtual ~Packet() { /* Intentionally empty */ };

        virtual PacketType getType() const { return PacketType::INTERFACE; };
};



class IntegerPacket : public Packet
{
    public:
        IntegerPacket(int32_t data) :data_(data) { /* Intentionally empty */ };

        PacketType getType() const override { return PacketType::INTEGER; };
        int32_t getData() const { return data_; };
    
    private:
        int32_t data_;
};



class ListPacket : public Packet
{
    public:
        ~ListPacket() override;

        PacketType getType() const override { return PacketType::LIST; };
        std::vector<Packet*> getData() const { return data_; };
        size_t getSize() const { return data_.size(); };

        void addData(Packet* data) { data_.push_back(data); };

    private:
        std::vector<Packet*> data_;
};

bool packetLessThan(const Packet* baseLhs, const Packet* baseRhs);