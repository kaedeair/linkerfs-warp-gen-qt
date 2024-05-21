/*
 * linkerfs_warp_gen_qt: warp configuration file generator backend for project linkerfs
 * Copyright (C) 2024  kaedeair <kaedeair@outlook.com>
 *
 * This file is part of linkerfs_warp_gen_qt.
 *
 * linkerfs_warp_gen_qt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * linkerfs_warp_gen_qt is distributed in the hope that it will be useful,but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with linkerfs_warp_gen_qt. If not, see <https://www.gnu.org/licenses/>.
 */

#include "File.hpp"

namespace Utils::File {

    DirEntry listDir(const QDir &dir, const QDir::Filter &filter) {
        DirEntry dirEntry;
        auto items = dir.entryInfoList(filter);
        for (const auto &item: items) {
            if (item.isFile()) {
                dirEntry.fileList.push_back(item.fileName());
            } else if (item.isDir()) {
                dirEntry.dirList.push_back(QPair<QString, bool>(item.fileName(), QDir(item.path()).isEmpty()));
            }
        }
        dirEntry.dirPath = dir.path();
        return dirEntry;
    }
}