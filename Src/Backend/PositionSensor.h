#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include "DigitalPart.h"

namespace so {
    class PositionSensor : public DigitalPart
    {
        public:

    		PositionSensor(EmbSysLib::Dev::Digital& digitalPort)
    		: DigitalPart(digitalPort)
    		, m_position(0)
    		{}

            void updateLeft();
            void updateRight();
            void reset();
            int getPosition() const;

        protected:

        private:

            int m_position;
    };

}
#endif //POSITIONSENSOR_H
