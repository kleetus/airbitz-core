/**
 * @file
 * Functions for dealing with the contents of the account sync directory.
 *
 *  Copyright (c) 2014, Airbitz
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms are permitted provided that
 *  the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *  list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *  3. Redistribution or use of modified source code requires the express written
 *  permission of Airbitz Inc.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  The views and conclusions contained in the software and documentation are those
 *  of the authors and should not be interpreted as representing official policies,
 *  either expressed or implied, of the Airbitz Project.
 *
 *  @author See AUTHORS
 *  @version 1.0
 */

#ifndef ABC_Account_h
#define ABC_Account_h

#include "ABC.h"
#include "util/ABC_Sync.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Account-level wallet structure.
     *
     * This structure contains the information stored for a wallet at thee
     * account level.
     */
    typedef struct sABC_AccountWalletInfo
    {
        /** Unique wallet id. */
        char *szUUID;
        /** Bitcoin master seed. */
        tABC_U08Buf BitcoinSeed;
        /** The sync key used to access the server. */
        tABC_U08Buf SyncKey;
        /** The encryption key used to protect the contents. */
        tABC_U08Buf MK;
        /** Sort order. */
        unsigned sortIndex;
        /** True if the wallet should be hidden. */
        bool archived;
    } tABC_AccountWalletInfo;

    tABC_CC ABC_AccountCategoriesLoad(tABC_SyncKeys *pKeys,
                                      char ***paszCategories,
                                      unsigned int *pCount,
                                      tABC_Error *pError);

    tABC_CC ABC_AccountCategoriesAdd(tABC_SyncKeys *pKeys,
                                     char *szCategory,
                                     tABC_Error *pError);

    tABC_CC ABC_AccountCategoriesRemove(tABC_SyncKeys *pKeys,
                                        char *szCategory,
                                        tABC_Error *pError);

    tABC_CC ABC_AccountSettingsLoad(tABC_SyncKeys *pKeys,
                                    tABC_AccountSettings **ppSettings,
                                    tABC_Error *pError);

    tABC_CC ABC_AccountSettingsSave(tABC_SyncKeys *pKeys,
                                    tABC_AccountSettings *pSettings,
                                    tABC_Error *pError);

    void ABC_AccountSettingsFree(tABC_AccountSettings *pSettings);

    void ABC_AccountWalletInfoFree(tABC_AccountWalletInfo *pInfo);
    void ABC_AccountWalletInfoFreeArray(tABC_AccountWalletInfo *aInfo,
                                        unsigned count);

    tABC_CC ABC_AccountWalletList(tABC_SyncKeys *pKeys,
                                  char ***paszUUID,
                                  unsigned *pCount,
                                  tABC_Error *pError);

    tABC_CC ABC_AccountWalletsLoad(tABC_SyncKeys *pKeys,
                                   tABC_AccountWalletInfo **paInfo,
                                   unsigned *pCount,
                                   tABC_Error *pError);

    tABC_CC ABC_AccountWalletLoad(tABC_SyncKeys *pKeys,
                                  const char *szUUID,
                                  tABC_AccountWalletInfo *pInfo,
                                  tABC_Error *pError);

    tABC_CC ABC_AccountWalletSave(tABC_SyncKeys *pKeys,
                                  tABC_AccountWalletInfo *pInfo,
                                  tABC_Error *pError);

    tABC_CC ABC_AccountWalletReorder(tABC_SyncKeys *pKeys,
                                     char **aszUUID,
                                     unsigned count,
                                     tABC_Error *pError);

#ifdef __cplusplus
}
#endif

#endif
