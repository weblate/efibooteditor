// SPDX-License-Identifier: LGPL-3.0-or-later
#pragma once

#include <QMetaType>
#include <QUuid>
#include <QVector>

#if defined(_MSC_VER)
#pragma warning(push)
// C4820: 'bytes' bytes padding added after construct 'member_name'
#pragma warning(disable : 4820)
#endif

class DriveInfo
{
    static QVector<DriveInfo> all;

public:
    enum class SIGNATURE : uint8_t
    {
        NONE = 0x00,
        MBR = 0x01,
        GUID = 0x02,
    };

public:
    QString name = "";
    uint32_t partition = 0;
    SIGNATURE signature_type = SIGNATURE::NONE;
    QUuid signature = {};
    uint64_t start = 0;
    uint64_t size = 0;

public:
    static QVector<DriveInfo> getAll(bool refresh = false);

    bool operator<(const DriveInfo &info) const { return name < info.name; }
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

Q_DECLARE_METATYPE(DriveInfo)
