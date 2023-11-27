#include "Packet.h"

#include <assert.h>

ListPacket::~ListPacket()
{
    for(auto packet : data_)
    {
        delete packet;
    }
};



bool packetLessThan(const Packet* baseLhs, const Packet* baseRhs)
{
    if (baseLhs->getType() < PacketType::INTEGER || baseRhs->getType() < PacketType::INTEGER)
    {
        assert(false);
    }

    // typeCombo will be two bits; lhs-type / rhs-type
    int8_t typeCombo = ((int8_t)(baseLhs->getType()) << 1) + (int8_t)baseRhs->getType();
    switch (typeCombo)
    {
        case 0: // 00  int /  int
        {
            const IntegerPacket* lhs = static_cast<const IntegerPacket*>(baseLhs);
            const IntegerPacket* rhs = static_cast<const IntegerPacket*>(baseRhs);
            return lhs->getData() < rhs->getData();
        }

        case 1: // 01  int / list
        {
            const IntegerPacket* lhs = static_cast<const IntegerPacket*>(baseLhs);
            const ListPacket* rhs = static_cast<const ListPacket*>(baseRhs);

            if(rhs->getSize() <= 0)
            {
                return false;
            }

            if(packetLessThan(lhs, rhs->getData()[0]))
            {
                return true;
            }
            if(packetLessThan(rhs->getData()[0], lhs))
            {
                return false;
            }

            return rhs->getSize() > 1;
        }

        case 2: // 10 list /  int
        {
            const ListPacket* lhs = static_cast<const ListPacket*>(baseLhs);
            const IntegerPacket* rhs = static_cast<const IntegerPacket*>(baseRhs);

            if(lhs->getSize() <= 0)
            {
                return true;
            }

            return packetLessThan(lhs->getData()[0], rhs);
        }
            
        case 3: // 11 list / list
        {
            const ListPacket* lhs = static_cast<const ListPacket*>(baseLhs);
            const ListPacket* rhs = static_cast<const ListPacket*>(baseRhs);

            if(rhs->getSize() <= 0)
            {
                return false;
            }
            else if(lhs->getSize() <= 0)
            {
                return true;
            }

            int i = 0;
            for(i = 0; i < lhs->getSize() && i < rhs->getSize(); i++)
            {
                if(packetLessThan(lhs->getData()[i], rhs->getData()[i]))
                {
                    return true;
                }
                if(packetLessThan(rhs->getData()[i], lhs->getData()[i]))
                {
                    return false;
                }
            }

            return i < rhs->getSize(); // if the lhs size is smaller than rhs
        }
        
        default:
            assert(false);
    };
    assert(false);
};