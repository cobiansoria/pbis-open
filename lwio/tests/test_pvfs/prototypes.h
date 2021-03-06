/* Editor Settings: expandtabs and use 4 spaces for indentation
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * -*- mode: c, c-basic-offset: 4 -*- */

/*
 * Copyright © BeyondTrust Software 2004 - 2019
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * BEYONDTRUST MAKES THIS SOFTWARE AVAILABLE UNDER OTHER LICENSING TERMS AS
 * WELL. IF YOU HAVE ENTERED INTO A SEPARATE LICENSE AGREEMENT WITH
 * BEYONDTRUST, THEN YOU MAY ELECT TO USE THE SOFTWARE UNDER THE TERMS OF THAT
 * SOFTWARE LICENSE AGREEMENT INSTEAD OF THE TERMS OF THE APACHE LICENSE,
 * NOTWITHSTANDING THE ABOVE NOTICE.  IF YOU HAVE QUESTIONS, OR WISH TO REQUEST
 * A COPY OF THE ALTERNATE LICENSING TERMS OFFERED BY BEYONDTRUST, PLEASE CONTACT
 * BEYONDTRUST AT beyondtrust.com/contact
 */

/*
 * Copyright (C) BeyondTrust Software. All rights reserved.
 *
 * Module Name:
 *
 *        main.c
 *
 * Abstract:
 *
 *        BeyondTrust IO (LWIO)
 *
 *        Test Program for exercising the PVFS driver
 *
 * Authors: Gerald Carter <gcarter@likewise.com>
 *
 */


#ifndef _TEST_PVFS_PROTOTYPES_H_
#define _TEST_PVFS_PROTOTYPES_H_

#include "includes.h"

void
PrintUsage(
    char *pszProgName
    );

NTSTATUS
CopyFileToPvfs(
    int argc,
    char *argv[]
    );

NTSTATUS
CopyFileFromPvfs(
    int argc,
    char *argv[]
    );

NTSTATUS
CatFileFromPvfs(
    char *pszFilename
    );


NTSTATUS
StatRemoteFile(
    char *pszFilename
    );

VOID
PrintFileBothDirInformation(
    PFILE_BOTH_DIR_INFORMATION pFileInfo
    );

NTSTATUS
ListDirectory(
    char *pszDirectory,
    char *pszPattern
    );

NTSTATUS
DeletePath(
    char *pszPath
    );

NTSTATUS
SetEndOfFile(
    int argc,
    char *argv[]
    );

NTSTATUS
LockTest(
    char *pszPath
    );

NTSTATUS
RequestOplock(
    int argc,
    char *argv[]
    );

NTSTATUS
ListOpenFiles(
    char *pszInfoLevel
    );

NTSTATUS
TestReadDirectoryChange(
    char *pszFilename
    );

NTSTATUS
PrintMaxOpenFiles(
    VOID
    );

NTSTATUS
GetFileSecurity(
    char *pszFilename
    );

NTSTATUS
SetFileSecurity(
    int argc,
    char *argv[]
    );



#endif /* _TEST_PVFS_PROTOTYPES_H_ */



/*
local variables:
mode: c
c-basic-offset: 4
indent-tabs-mode: nil
tab-width: 4
end:
*/
