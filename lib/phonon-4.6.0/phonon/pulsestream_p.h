/*  This file is part of the KDE project
    Copyright (C) 2010 Colin Guthrie <cguthrie@mandriva.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), Nokia Corporation
    (or its successors, if any) and the KDE Free Qt Foundation, which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef PHONON_PULSESTREAM_P_H
#define PHONON_PULSESTREAM_P_H

#include <QtCore/QtGlobal>

#include <pulse/pulseaudio.h>
#include <stdint.h>

#include "phonon_export.h"
#include "phononnamespace.h"

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

namespace Phonon
{
    class PHONON_EXPORT PulseStream : public QObject
    {
        Q_OBJECT
        public:
            PulseStream(QString streamUuid);
            ~PulseStream();

            QString uuid();

            uint32_t index();
            void setIndex(uint32_t index);

            uint8_t channels();

            void setDevice(int device);
            void setVolume(const pa_cvolume *volume);
            void setMute(bool mute);

        signals:
            void usingDevice(int device);
            void volumeChanged(qreal volume);
            void muteChanged(bool mute);

        private:
            QString mStreamUuid;
            uint32_t mIndex;
            int mDevice;
            pa_cvolume mVolume;
            bool mMute;
    };
} // namespace Phonon

QT_END_NAMESPACE
QT_END_HEADER

#endif // PHONON_PULSESTREAM_P_H