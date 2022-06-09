/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_
#define BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_

#include <vector>

#include "base/no_destructor.h"
#include "brave/components/brave_wallet/common/brave_wallet.mojom.h"
#include "brave/components/brave_wallet/common/brave_wallet_types.h"
#include "components/grit/brave_components_strings.h"
#include "ui/base/webui/web_ui_util.h"

namespace brave_wallet {

constexpr char kAssetRatioBaseURL[] = "https://ratios.rewards.brave.com/";

constexpr uint256_t kDefaultSendEthGasLimit = 21000;
constexpr uint256_t kDefaultERC20TransferGasLimit = 300000;
constexpr uint256_t kDefaultERC721TransferGasLimit = 800000;
constexpr uint256_t kDefaultERC20ApproveGasLimit = 300000;

constexpr int32_t kAutoLockMinutesMin = 1;
constexpr int32_t kAutoLockMinutesMax = 10080;

constexpr char kWalletBaseDirectory[] = "BraveWallet";
constexpr char kImageSourceHost[] = "erc-token-images";
constexpr char kWyreID[] = "AC_MGNVBGHPA9T";
constexpr char kWyreBuyUrl[] =
    "https://pay.sendwyre.com/?dest=ethereum:%s"
    "&destCurrency=%s&amount=%s&accountId=%s&paymentMethod=debit-card";
constexpr char kRampBuyUrl[] =
    "https://buy.ramp.network/"
    "?userAddress=%s&swapAsset=%s&fiatValue=%s&fiatCurrency=USD&hostApiKey=%s";
constexpr char kRampID[] = "8yxja8782as5essk2myz3bmh4az6gpq4nte9n2gf";

constexpr webui::LocalizedString kLocalizedStrings[] = {
    {"braveWallet", IDS_BRAVE_WALLET},
    {"braveWalletDefiCategory", IDS_BRAVE_WALLET_DEFI_CATEGORY},
    {"braveWalletNftCategory", IDS_BRAVE_WALLET_NFT_CATEGORY},
    {"braveWalletSearchCategory", IDS_BRAVE_WALLET_SEARCH_CATEGORY},
    {"braveWalletDefiButtonText", IDS_BRAVE_WALLET_DEFI_BUTTON_TEXT},
    {"braveWalletNftButtonText", IDS_BRAVE_WALLET_NFT_BUTTON_TEXT},
    {"braveWalletCompoundName", IDS_BRAVE_WALLET_COMPOUND_NAME},
    {"braveWalletCompoundDescription", IDS_BRAVE_WALLET_COMPOUND_DESCRIPTION},
    {"braveWalletMakerName", IDS_BRAVE_WALLET_MAKER_NAME},
    {"braveWalletMakerDescription", IDS_BRAVE_WALLET_MAKER_DESCRIPTION},
    {"braveWalletAaveName", IDS_BRAVE_WALLET_AAVE_NAME},
    {"braveWalletAaveDescription", IDS_BRAVE_WALLET_AAVE_DESCRIPTION},
    {"braveWalletOpenSeaName", IDS_BRAVE_WALLET_OPEN_SEA_NAME},
    {"braveWalletOpenSeaDescription", IDS_BRAVE_WALLET_OPEN_SEA_DESCRIPTION},
    {"braveWalletRaribleName", IDS_BRAVE_WALLET_RARIBLE_NAME},
    {"braveWalletRaribleDescription", IDS_BRAVE_WALLET_RARIBLE_DESCRIPTION},
    {"braveWalletSearchText", IDS_BRAVE_WALLET_SEARCH_TEXT},
    {"braveWalletSideNavCrypto", IDS_BRAVE_WALLET_SIDE_NAV_CRYPTO},
    {"braveWalletSideNavRewards", IDS_BRAVE_WALLET_SIDE_NAV_REWARDS},
    {"braveWalletSideNavCards", IDS_BRAVE_WALLET_SIDE_NAV_CARDS},
    {"braveWalletTopNavPortfolio", IDS_BRAVE_WALLET_TOP_NAV_PORTFOLIO},
    {"braveWalletTopTabPrices", IDS_BRAVE_WALLET_TOP_TAB_PRICES},
    {"braveWalletTopTabApps", IDS_BRAVE_WALLET_TOP_TAB_APPS},
    {"braveWalletTopNavNFTS", IDS_BRAVE_WALLET_TOP_NAV_N_F_T_S},
    {"braveWalletTopNavAccounts", IDS_BRAVE_WALLET_TOP_NAV_ACCOUNTS},
    {"braveWalletChartLive", IDS_BRAVE_WALLET_CHART_LIVE},
    {"braveWalletChartOneDay", IDS_BRAVE_WALLET_CHART_ONE_DAY},
    {"braveWalletChartOneWeek", IDS_BRAVE_WALLET_CHART_ONE_WEEK},
    {"braveWalletChartOneMonth", IDS_BRAVE_WALLET_CHART_ONE_MONTH},
    {"braveWalletChartThreeMonths", IDS_BRAVE_WALLET_CHART_THREE_MONTHS},
    {"braveWalletChartOneYear", IDS_BRAVE_WALLET_CHART_ONE_YEAR},
    {"braveWalletChartAllTime", IDS_BRAVE_WALLET_CHART_ALL_TIME},
    {"braveWalletAddCoin", IDS_BRAVE_WALLET_ADD_COIN},
    {"braveWalletBalance", IDS_BRAVE_WALLET_BALANCE},
    {"braveWalletPortfolioAssetNetworkDescription",
     IDS_BRAVE_WALLET_PORTFOLIO_ASSET_NETWORK_DESCRIPTION},
    {"braveWalletAccounts", IDS_BRAVE_WALLET_ACCOUNTS},
    {"braveWalletAccount", IDS_BRAVE_WALLET_ACCOUNT},
    {"braveWalletOwner", IDS_BRAVE_WALLET_OWNER},
    {"braveWalletTransactions", IDS_BRAVE_WALLET_TRANSACTIONS},
    {"braveWalletPrice", IDS_BRAVE_WALLET_PRICE},
    {"braveWalletBack", IDS_BRAVE_WALLET_BACK},
    {"braveWalletAddAccount", IDS_BRAVE_WALLET_ADD_ACCOUNT},
    {"braveWalletPoweredByCoinGecko", IDS_BRAVE_WALLET_POWERED_BY_COIN_GECKO},
    {"braveWalletBuy", IDS_BRAVE_WALLET_BUY},
    {"braveWalletSend", IDS_BRAVE_WALLET_SEND},
    {"braveWalletSwap", IDS_BRAVE_WALLET_SWAP},
    {"braveWalletReset", IDS_BRAVE_WALLET_RESET},
    {"braveWalletBuyNotSupportedTooltip",
     IDS_BRAVE_WALLET_BUY_NOT_SUPPORTED_TOOLTIP},
    {"braveWalletSwapNotSupportedTooltip",
     IDS_BRAVE_WALLET_SWAP_NOT_SUPPORTED_TOOLTIP},
    {"braveWalletSlippageToleranceWarning",
     IDS_BRAVE_WALLET_SLIPPAGE_TOLERANCE_WARNING},
    {"braveWalletSlippageToleranceTitle",
     IDS_BRAVE_WALLET_SLIPPAGE_TOLERANCE_TITLE},
    {"braveWalletExpiresInTitle", IDS_BRAVE_WALLET_EXPIRES_IN_TITLE},
    {"braveWalletSendPlaceholder", IDS_BRAVE_WALLET_SEND_PLACEHOLDER},
    {"braveWalletSendNoURLPlaceholder",
     IDS_BRAVE_WALLET_SEND_NO_URL_PLACEHOLDER},
    {"braveWalletSwapDisclaimer", IDS_BRAVE_WALLET_SWAP_DISCLAIMER},
    {"braveWalletSwapDisclaimerDescription",
     IDS_BRAVE_WALLET_SWAP_DISCLAIMER_DESCRIPTION},
    {"braveWalletSwapFeesNotice", IDS_BRAVE_WALLET_SWAP_FEES_NOTICE},
    {"braveWalletDecimalPlacesError", IDS_BRAVE_WALLET_DECIMAL_PLACES_ERROR},
    {"braveWalletCreateAccountDescription",
     IDS_BRAVE_WALLET_CREATE_ACCOUNT_DESCRIPTION},
    {"braveWalletCreateAccountYes", IDS_BRAVE_WALLET_CREATE_ACCOUNT_YES},
    {"braveWalletCreateAccountNo", IDS_BRAVE_WALLET_CREATE_ACCOUNT_NO},
    {"braveWalletButtonContinue", IDS_BRAVE_WALLET_BUTTON_CONTINUE},
    {"braveWalletButtonCopy", IDS_BRAVE_WALLET_BUTTON_COPY},
    {"braveWalletButtonCopied", IDS_BRAVE_WALLET_BUTTON_COPIED},
    {"braveWalletButtonVerify", IDS_BRAVE_WALLET_BUTTON_VERIFY},
    {"braveWalletWelcomeTitle", IDS_BRAVE_WALLET_WELCOME_TITLE},
    {"braveWalletWelcomeDescription", IDS_BRAVE_WALLET_WELCOME_DESCRIPTION},
    {"braveWalletWelcomeButton", IDS_BRAVE_WALLET_WELCOME_BUTTON},
    {"braveWalletWelcomeRestoreButton",
     IDS_BRAVE_WALLET_WELCOME_RESTORE_BUTTON},
    {"braveWalletBackupIntroTitle", IDS_BRAVE_WALLET_BACKUP_INTRO_TITLE},
    {"braveWalletBackupIntroDescription",
     IDS_BRAVE_WALLET_BACKUP_INTRO_DESCRIPTION},
    {"braveWalletBackupIntroTerms", IDS_BRAVE_WALLET_BACKUP_INTRO_TERMS},
    {"braveWalletBackupButtonSkip", IDS_BRAVE_WALLET_BACKUP_BUTTON_SKIP},
    {"braveWalletBackupButtonCancel", IDS_BRAVE_WALLET_BACKUP_BUTTON_CANCEL},
    {"braveWalletRecoveryTitle", IDS_BRAVE_WALLET_RECOVERY_TITLE},
    {"braveWalletRecoveryDescription", IDS_BRAVE_WALLET_RECOVERY_DESCRIPTION},
    {"braveWalletRecoveryWarning1", IDS_BRAVE_WALLET_RECOVERY_WARNING1},
    {"braveWalletRecoveryWarning2", IDS_BRAVE_WALLET_RECOVERY_WARNING2},
    {"braveWalletRecoveryWarning3", IDS_BRAVE_WALLET_RECOVERY_WARNING3},
    {"braveWalletRecoveryTerms", IDS_BRAVE_WALLET_RECOVERY_TERMS},
    {"braveWalletVerifyRecoveryTitle", IDS_BRAVE_WALLET_VERIFY_RECOVERY_TITLE},
    {"braveWalletVerifyRecoveryDescription",
     IDS_BRAVE_WALLET_VERIFY_RECOVERY_DESCRIPTION},
    {"braveWalletVerifyError", IDS_BRAVE_WALLET_VERIFY_ERROR},
    {"braveWalletCreatePasswordTitle", IDS_BRAVE_WALLET_CREATE_PASSWORD_TITLE},
    {"braveWalletCreatePasswordDescription",
     IDS_BRAVE_WALLET_CREATE_PASSWORD_DESCRIPTION},
    {"braveWalletCreatePasswordInput", IDS_BRAVE_WALLET_CREATE_PASSWORD_INPUT},
    {"braveWalletConfirmPasswordInput",
     IDS_BRAVE_WALLET_CONFIRM_PASSWORD_INPUT},
    {"braveWalletCreatePasswordError", IDS_BRAVE_WALLET_CREATE_PASSWORD_ERROR},
    {"braveWalletConfirmPasswordError",
     IDS_BRAVE_WALLET_CONFIRM_PASSWORD_ERROR},
    {"braveWalletLockScreenTitle", IDS_BRAVE_WALLET_LOCK_SCREEN_TITLE},
    {"braveWalletLockScreenButton", IDS_BRAVE_WALLET_LOCK_SCREEN_BUTTON},
    {"braveWalletLockScreenError", IDS_BRAVE_WALLET_LOCK_SCREEN_ERROR},
    {"braveWalletWalletPopupSettings", IDS_BRAVE_WALLET_WALLET_POPUP_SETTINGS},
    {"braveWalletWalletPopupLock", IDS_BRAVE_WALLET_WALLET_POPUP_LOCK},
    {"braveWalletWalletPopupBackup", IDS_BRAVE_WALLET_WALLET_POPUP_BACKUP},
    {"braveWalletWalletPopupConnectedSites",
     IDS_BRAVE_WALLET_WALLET_POPUP_CONNECTED_SITES},
    {"braveWalletBackupWarningText", IDS_BRAVE_WALLET_BACKUP_WARNING_TEXT},
    {"braveWalletBackupButton", IDS_BRAVE_WALLET_BACKUP_BUTTON},
    {"braveWalletDismissButton", IDS_BRAVE_WALLET_DISMISS_BUTTON},
    {"braveWalletDefaultWalletBanner", IDS_BRAVE_WALLET_DEFAULT_WALLET_BANNER},
    {"braveWalletRestoreTite", IDS_BRAVE_WALLET_RESTORE_TITE},
    {"braveWalletRestoreDescription", IDS_BRAVE_WALLET_RESTORE_DESCRIPTION},
    {"braveWalletRestoreError", IDS_BRAVE_WALLET_RESTORE_ERROR},
    {"braveWalletRestorePlaceholder", IDS_BRAVE_WALLET_RESTORE_PLACEHOLDER},
    {"braveWalletRestoreShowPhrase", IDS_BRAVE_WALLET_RESTORE_SHOW_PHRASE},
    {"braveWalletRestoreLegacyCheckBox",
     IDS_BRAVE_WALLET_RESTORE_LEGACY_CHECK_BOX},
    {"braveWalletRestoreFormText", IDS_BRAVE_WALLET_RESTORE_FORM_TEXT},
    {"braveWalletToolTipCopyToClipboard",
     IDS_BRAVE_WALLET_TOOL_TIP_COPY_TO_CLIPBOARD},
    {"braveWalletAccountsPrimary", IDS_BRAVE_WALLET_ACCOUNTS_PRIMARY},
    {"braveWalletAccountsPrimaryDisclaimer",
     IDS_BRAVE_WALLET_ACCOUNTS_PRIMARY_DISCLAIMER},
    {"braveWalletAccountsSecondary", IDS_BRAVE_WALLET_ACCOUNTS_SECONDARY},
    {"braveWalletAccountsSecondaryDisclaimer",
     IDS_BRAVE_WALLET_ACCOUNTS_SECONDARY_DISCLAIMER},
    {"braveWalletAccountsAssets", IDS_BRAVE_WALLET_ACCOUNTS_ASSETS},
    {"braveWalletAccountsEditVisibleAssets",
     IDS_BRAVE_WALLET_ACCOUNTS_EDIT_VISIBLE_ASSETS},
    {"braveWalletAddAccountCreate", IDS_BRAVE_WALLET_ADD_ACCOUNT_CREATE},
    {"braveWalletCreateAccount", IDS_BRAVE_WALLET_CREATE_ACCOUNT},
    {"braveWalletCreateAccountButton", IDS_BRAVE_WALLET_CREATE_ACCOUNT_BUTTON},
    {"braveWalletCreateAccountImportAccount",
     IDS_BRAVE_WALLET_CREATE_ACCOUNT_IMPORT_ACCOUNT},
    {"braveWalletCreateAccountTitle", IDS_BRAVE_WALLET_CREATE_ACCOUNT_TITLE},
    {"braveWalletCreateAccountEthereumDescription",
     IDS_BRAVE_WALLET_CREATE_ACCOUNT_ETHEREUM_DESCRIPTION},
    {"braveWalletCreateAccountSolanaDescription",
     IDS_BRAVE_WALLET_CREATE_ACCOUNT_SOLANA_DESCRIPTION},
    {"braveWalletCreateAccountFilecoinDescription",
     IDS_BRAVE_WALLET_CREATE_ACCOUNT_FILECOIN_DESCRIPTION},
    {"braveWalletFilecoinPrivateKeyProtocol",
     IDS_BRAVE_WALLET_FILECOIN_PRIVATE_KEY_PROTOCOL},
    {"braveWalletAddAccountImport", IDS_BRAVE_WALLET_ADD_ACCOUNT_IMPORT},
    {"braveWalletAddAccountImportHardware",
     IDS_BRAVE_WALLET_ADD_ACCOUNT_IMPORT_HARDWARE},
    {"braveWalletAddAccountHardware", IDS_BRAVE_WALLET_ADD_ACCOUNT_HARDWARE},
    {"braveWalletAddAccountConnect", IDS_BRAVE_WALLET_ADD_ACCOUNT_CONNECT},
    {"braveWalletAddAccountPlaceholder",
     IDS_BRAVE_WALLET_ADD_ACCOUNT_PLACEHOLDER},
    {"braveWalletImportAccountDisclaimer",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_DISCLAIMER},
    {"braveWalletImportAccountPlaceholder",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_PLACEHOLDER},
    {"braveWalletImportAccountKey", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_KEY},
    {"braveWalletImportAccountFile", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_FILE},
    {"braveWalletImportAccountUploadButton",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_UPLOAD_BUTTON},
    {"braveWalletImportAccountUploadPlaceholder",
     IDS_BRAVE_WALLET_IMPORT_ACCOUNT_UPLOAD_PLACEHOLDER},
    {"braveWalletImportAccountError", IDS_BRAVE_WALLET_IMPORT_ACCOUNT_ERROR},
    {"braveWalletConnectHardwareTitle",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_TITLE},
    {"braveWalletConnectHardwareInfo1",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_INFO1},
    {"braveWalletConnectHardwareInfo2",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_INFO2},
    {"braveWalletConnectHardwareWrongApplicationUserHint",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_WRONG_APPLICATION_USER_HINT},
    {"braveWalletConnectHardwareTrezor",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_TREZOR},
    {"braveWalletConnectHardwareLedger",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_LEDGER},
    {"braveWalletConnectingHardwareWallet",
     IDS_BRAVE_WALLET_CONNECTING_HARDWARE_WALLET},
    {"braveWalletAddCheckedAccountsHardwareWallet",
     IDS_BRAVE_WALLET_ADD_CHECKED_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletLoadMoreAccountsHardwareWallet",
     IDS_BRAVE_WALLET_LOAD_MORE_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletLoadingMoreAccountsHardwareWallet",
     IDS_BRAVE_WALLET_LOADING_MORE_ACCOUNTS_HARDWARE_WALLET},
    {"braveWalletSearchScannedAccounts",
     IDS_BRAVE_WALLET_SEARCH_SCANNED_ACCOUNTS},
    {"braveWalletSwitchHDPathTextHardwareWallet",
     IDS_BRAVE_WALLET_SWITCH_H_D_PATH_TEXT_HARDWARE_WALLET},
    {"braveWalletLedgerLiveDerivationPath",
     IDS_BRAVE_WALLET_LEDGER_LIVE_DERIVATION_PATH},
    {"braveWalletLedgerLegacyDerivationPath",
     IDS_BRAVE_WALLET_LEDGER_LEGACY_DERIVATION_PATH},
    {"braveWalletConnectHardwareSearchNothingFound",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_SEARCH_NOTHING_FOUND},
    {"braveWalletUnknownInternalError",
     IDS_BRAVE_WALLET_UNKNOWN_INTERNAL_ERROR},
    {"braveWalletAccountSettingsDetails",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_DETAILS},
    {"braveWalletAccountSettingsWatchlist",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_WATCHLIST},
    {"braveWalletAccountSettingsPrivateKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_PRIVATE_KEY},
    {"braveWalletAccountSettingsSave", IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_SAVE},
    {"braveWalletAccountSettingsRemove",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_REMOVE},
    {"braveWalletWatchlistAddCustomAsset",
     IDS_BRAVE_WALLET_WATCHLIST_ADD_CUSTOM_ASSET},
    {"braveWalletWatchListTokenName", IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_NAME},
    {"braveWalletWatchListTokenAddress",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ADDRESS},
    {"braveWalletWatchListTokenSymbol",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_SYMBOL},
    {"braveWalletWatchListTokenDecimals",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_DECIMALS},
    {"braveWalletWatchListAdd", IDS_BRAVE_WALLET_WATCH_LIST_ADD},
    {"braveWalletWatchListDoneButton", IDS_BRAVE_WALLET_WATCH_LIST_DONE_BUTTON},
    {"braveWalletWatchListSuggestion", IDS_BRAVE_WALLET_WATCH_LIST_SUGGESTION},
    {"braveWalletWatchListNoAsset", IDS_BRAVE_WALLET_WATCH_LIST_NO_ASSET},
    {"braveWalletWatchListSearchPlaceholder",
     IDS_BRAVE_WALLET_WATCH_LIST_SEARCH_PLACEHOLDER},
    {"braveWalletWatchListError", IDS_BRAVE_WALLET_WATCH_LIST_ERROR},
    {"braveWalletWatchListTokenId", IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ID},
    {"braveWalletWatchListTokenIdError",
     IDS_BRAVE_WALLET_WATCH_LIST_TOKEN_ID_ERROR},
    {"braveWalletWatchListAdvanced", IDS_BRAVE_WALLET_WATCH_LIST_ADVANCED},
    {"braveWalletWatchListCoingeckoId",
     IDS_BRAVE_WALLET_WATCH_LIST_COINGECKO_ID},
    {"braveWalletIconURL", IDS_BRAVE_WALLET_ICON_URL},
    {"braveWalletAddAsset", IDS_BRAVE_WALLET_ADD_ASSET},
    {"braveWalletAccountSettingsDisclaimer",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_DISCLAIMER},
    {"braveWalletAccountSettingsShowKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_SHOW_KEY},
    {"braveWalletAccountSettingsHideKey",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_HIDE_KEY},
    {"braveWalletAccountSettingsUpdateError",
     IDS_BRAVE_WALLET_ACCOUNT_SETTINGS_UPDATE_ERROR},
    {"braveWalletPreset25", IDS_BRAVE_WALLET_PRESET25},
    {"braveWalletPreset50", IDS_BRAVE_WALLET_PRESET50},
    {"braveWalletPreset75", IDS_BRAVE_WALLET_PRESET75},
    {"braveWalletPreset100", IDS_BRAVE_WALLET_PRESET100},
    {"braveWalletNetworkETH", IDS_BRAVE_WALLET_NETWORK_E_T_H},
    {"braveWalletNetworkMain", IDS_BRAVE_WALLET_NETWORK_MAIN},
    {"braveWalletNetworkTest", IDS_BRAVE_WALLET_NETWORK_TEST},
    {"braveWalletNetworkRopsten", IDS_BRAVE_WALLET_NETWORK_ROPSTEN},
    {"braveWalletNetworkKovan", IDS_BRAVE_WALLET_NETWORK_KOVAN},
    {"braveWalletNetworkRinkeby", IDS_BRAVE_WALLET_NETWORK_RINKEBY},
    {"braveWalletNetworkGoerli", IDS_BRAVE_WALLET_NETWORK_GOERLI},
    {"braveWalletNetworkBinance", IDS_BRAVE_WALLET_NETWORK_BINANCE},
    {"braveWalletNetworkBinanceAbbr", IDS_BRAVE_WALLET_NETWORK_BINANCE_ABBR},
    {"braveWalletNetworkLocalhost", IDS_BRAVE_WALLET_NETWORK_LOCALHOST},
    {"braveWalletSelectAccount", IDS_BRAVE_WALLET_SELECT_ACCOUNT},
    {"braveWalletSearchAccount", IDS_BRAVE_WALLET_SEARCH_ACCOUNT},
    {"braveWalletSelectNetwork", IDS_BRAVE_WALLET_SELECT_NETWORK},
    {"braveWalletSelectAsset", IDS_BRAVE_WALLET_SELECT_ASSET},
    {"braveWalletSearchAsset", IDS_BRAVE_WALLET_SEARCH_ASSET},
    {"braveWalletSwapFrom", IDS_BRAVE_WALLET_SWAP_FROM},
    {"braveWalletSwapTo", IDS_BRAVE_WALLET_SWAP_TO},
    {"braveWalletSwapEstimate", IDS_BRAVE_WALLET_SWAP_ESTIMATE},
    {"braveWalletSwapMarket", IDS_BRAVE_WALLET_SWAP_MARKET},
    {"braveWalletSwapLimit", IDS_BRAVE_WALLET_SWAP_LIMIT},
    {"braveWalletSwapPriceIn", IDS_BRAVE_WALLET_SWAP_PRICE_IN},
    {"braveWalletBuyTitle", IDS_BRAVE_WALLET_BUY_TITLE},
    {"braveWalletBuyDescription", IDS_BRAVE_WALLET_BUY_DESCRIPTION},
    {"braveWalletBuyContinueButton", IDS_BRAVE_WALLET_BUY_CONTINUE_BUTTON},
    {"braveWalletSignTransactionTitle",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_TITLE},
    {"braveWalletSignWarning", IDS_BRAVE_WALLET_SIGN_WARNING},
    {"braveWalletSignWarningTitle", IDS_BRAVE_WALLET_SIGN_WARNING_TITLE},
    {"braveWalletSignTransactionMessageTitle",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_MESSAGE_TITLE},
    {"braveWalletSignTransactionButton",
     IDS_BRAVE_WALLET_SIGN_TRANSACTION_BUTTON},
    {"braveWalletProvideEncryptionKeyTitle",
     IDS_BRAVE_WALLET_PROVIDE_ENCRYPTION_KEY_TITLE},
    {"braveWalletProvideEncryptionKeyDescription",
     IDS_BRAVE_WALLET_PROVIDE_ENCRYPTION_KEY_DESCRIPTION},
    {"braveWalletProvideEncryptionKeyButton",
     IDS_BRAVE_WALLET_PROVIDE_ENCRYPTION_KEY_BUTTON},
    {"braveWalletReadEncryptedMessageTitle",
     IDS_BRAVE_WALLET_READ_ENCRYPTED_MESSAGE_TITLE},
    {"braveWalletReadEncryptedMessageDecryptButton",
     IDS_BRAVE_WALLET_READ_ENCRYPTED_MESSAGE_DECRYPT_BUTTON},
    {"braveWalletReadEncryptedMessageButton",
     IDS_BRAVE_WALLET_READ_ENCRYPTED_MESSAGE_BUTTON},
    {"braveWalletAllowSpendTitle", IDS_BRAVE_WALLET_ALLOW_SPEND_TITLE},
    {"braveWalletAllowSpendDescription",
     IDS_BRAVE_WALLET_ALLOW_SPEND_DESCRIPTION},
    {"braveWalletAllowSpendBoxTitle", IDS_BRAVE_WALLET_ALLOW_SPEND_BOX_TITLE},
    {"braveWalletAllowSpendTransactionFee",
     IDS_BRAVE_WALLET_ALLOW_SPEND_TRANSACTION_FEE},
    {"braveWalletAllowSpendEditButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_EDIT_BUTTON},
    {"braveWalletAllowSpendDetailsButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_DETAILS_BUTTON},
    {"braveWalletAllowSpendRejectButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_REJECT_BUTTON},
    {"braveWalletAllowSpendConfirmButton",
     IDS_BRAVE_WALLET_ALLOW_SPEND_CONFIRM_BUTTON},
    {"braveWalletAllowSpendCurrentAllowance",
     IDS_BRAVE_WALLET_ALLOW_SPEND_CURRENT_ALLOWANCE},
    {"braveWalletAllowSpendProposedAllowance",
     IDS_BRAVE_WALLET_ALLOW_SPEND_PROPOSED_ALLOWANCE},
    {"braveWalletAllowSpendUnlimitedWarningTitle",
     IDS_BRAVE_WALLET_ALLOW_SPEND_UNLIMITED_WARNING_TITLE},
    {"braveWalletAllowAddNetworkTitle",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_TITLE},
    {"braveWalletAllowChangeNetworkTitle",
     IDS_BRAVE_WALLET_ALLOW_CHANGE_NETWORK_TITLE},
    {"braveWalletAllowChangeNetworkDescription",
     IDS_BRAVE_WALLET_ALLOW_CHANGE_NETWORK_DESCRIPTION},
    {"braveWalletAllowChangeNetworkButton",
     IDS_BRAVE_WALLET_ALLOW_CHANGE_NETWORK_BUTTON},
    {"braveWalletAllowAddNetworkDescription",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_DESCRIPTION},
    {"braveWalletAllowAddNetworkLearnMoreButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_LEARN_MORE_BUTTON},
    {"braveWalletAllowAddNetworkName", IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_NAME},
    {"braveWalletAllowAddNetworkUrl", IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_URL},
    {"braveWalletAllowAddNetworkDetailsButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_DETAILS_BUTTON},
    {"braveWalletAllowAddNetworkButton",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_BUTTON},
    {"braveWalletAllowAddNetworkChainID",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_CHAIN_I_D},
    {"braveWalletAllowAddNetworkCurrencySymbol",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_CURRENCY_SYMBOL},
    {"braveWalletAllowAddNetworkExplorer",
     IDS_BRAVE_WALLET_ALLOW_ADD_NETWORK_EXPLORER},
    {"braveWalletConfirmTransactionTotal",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_TOTAL},
    {"braveWalletConfirmTransactionGasFee",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_GAS_FEE},
    {"braveWalletConfirmTransactionTransactionFee",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_TRANSACTION_FEE},
    {"braveWalletConfirmTransactionBid",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_BID},
    {"braveWalletConfirmTransactionAmountGas",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_AMOUNT_GAS},
    {"braveWalletConfirmTransactionAmountFee",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_AMOUNT_FEE},
    {"braveWalletConfirmTransactionNoData",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_NO_DATA},
    {"braveWalletConfirmTransactionNext",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_NEXT},
    {"braveWalletConfirmTransactionFrist",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_FRIST},
    {"braveWalletConfirmTransactions", IDS_BRAVE_WALLET_CONFIRM_TRANSACTIONS},
    {"braveWalletConfirmTransactionAccountCreationFee",
     IDS_BRAVE_WALLET_CONFIRM_TRANSACTION_ACCOUNT_CREATION_FEE},
    {"braveWalletPanelTitle", IDS_BRAVE_WALLET_PANEL_TITLE},
    {"braveWalletPanelConnected", IDS_BRAVE_WALLET_PANEL_CONNECTED},
    {"braveWalletSitePermissionsAccounts",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_ACCOUNTS},
    {"braveWalletSitePermissionsTitle",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_TITLE},
    {"braveWalletSitePermissionsDisconnect",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_DISCONNECT},
    {"braveWalletSitePermissionsSwitch",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_SWITCH},
    {"braveWalletSitePermissionsNewAccount",
     IDS_BRAVE_WALLET_SITE_PERMISSIONS_NEW_ACCOUNT},
    {"braveWalletPanelNotConnected", IDS_BRAVE_WALLET_PANEL_NOT_CONNECTED},
    {"braveWalletPanelViewAccountAssets",
     IDS_BRAVE_WALLET_PANEL_VIEW_ACCOUNT_ASSETS},
    {"braveWalletAssetsPanelTitle", IDS_BRAVE_WALLET_ASSETS_PANEL_TITLE},
    {"braveWalletWelcomePanelDescription",
     IDS_BRAVE_WALLET_WELCOME_PANEL_DESCRIPTION},
    {"braveWalletWelcomePanelButton", IDS_BRAVE_WALLET_WELCOME_PANEL_BUTTON},
    {"braveWalletTransactionDetailBoxFunction",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_FUNCTION},
    {"braveWalletTransactionDetailBoxHex",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_HEX},
    {"braveWalletTransactionDetailBoxBytes",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_BOX_BYTES},
    {"braveWalletConnectWithSiteTitle",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_TITLE},
    {"braveWalletConnectWithSiteDescription",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_DESCRIPTION},
    {"braveWalletConnectWithSiteNext", IDS_BRAVE_WALLET_CONNECT_WITH_SITE_NEXT},
    {"braveWalletConnectWithSiteHeaderTitle",
     IDS_BRAVE_WALLET_CONNECT_WITH_SITE_HEADER_TITLE},
    {"braveWalletImportFromExternalNewPassword",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_NEW_PASSWORD},
    {"braveWalletImportFromExternalCreatePassword",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_CREATE_PASSWORD},
    {"braveWalletImportFromExternalPasswordCheck",
     IDS_BRAVE_WALLET_IMPORT_FROM_EXTERNAL_PASSWORD_CHECK},
    {"braveWalletImportMetaMaskTitle", IDS_BRAVE_WALLET_IMPORT_META_MASK_TITLE},
    {"braveWalletImportTitle", IDS_BRAVE_WALLET_IMPORT_TITLE},
    {"braveWalletImportDescription", IDS_BRAVE_WALLET_IMPORT_DESCRIPTION},
    {"braveWalletImportMetaMaskInput", IDS_BRAVE_WALLET_IMPORT_META_MASK_INPUT},
    {"braveWalletImportBraveLegacyTitle",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_TITLE},
    {"braveWalletCryptoWalletsDetected",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DETECTED},
    {"braveWalletCryptoWalletsDescriptionOne",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DESCRIPTION_ONE},
    {"braveWalletCryptoWalletsDescriptionTwo",
     IDS_BRAVE_WALLET_CRYPTO_WALLETS_DESCRIPTION_TWO},
    {"braveWalletImportBraveLegacyDescription",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_DESCRIPTION},
    {"braveWalletImportBraveLegacyInput",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_INPUT},
    {"braveWalletImportBraveLegacyAltButton",
     IDS_BRAVE_WALLET_IMPORT_BRAVE_LEGACY_ALT_BUTTON},
    {"braveWalletConnectHardwarePanelConnected",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONNECTED},
    {"braveWalletConnectHardwarePanelDisconnected",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_DISCONNECTED},
    {"braveWalletConnectHardwarePanelInstructions",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_INSTRUCTIONS},
    {"braveWalletConnectHardwarePanelConnect",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONNECT},
    {"braveWalletConnectHardwarePanelConfirmation",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_CONFIRMATION},
    {"braveWalletConnectHardwarePanelOpenApp",
     IDS_BRAVE_WALLET_CONNECT_HARDWARE_PANEL_OPEN_APP},
    {"braveWalletTransactionSent", IDS_BRAVE_WALLET_TRANSACTION_SENT},
    {"braveWalletTransactionReceived", IDS_BRAVE_WALLET_TRANSACTION_RECEIVED},
    {"braveWalletTransactionExplorerMissing",
     IDS_BRAVE_WALLET_TRANSACTION_EXPLORER_MISSING},
    {"braveWalletTransactionExplorer", IDS_BRAVE_WALLET_TRANSACTION_EXPLORER},
    {"braveWalletTransactionCopyHash", IDS_BRAVE_WALLET_TRANSACTION_COPY_HASH},
    {"braveWalletTransactionSpeedup", IDS_BRAVE_WALLET_TRANSACTION_SPEEDUP},
    {"braveWalletTransactionCancel", IDS_BRAVE_WALLET_TRANSACTION_CANCEL},
    {"braveWalletTransactionRetry", IDS_BRAVE_WALLET_TRANSACTION_RETRY},
    {"braveWalletTransactionStatusUnapproved",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_UNAPPROVED},
    {"braveWalletTransactionStatusApproved",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_APPROVED},
    {"braveWalletTransactionStatusRejected",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_REJECTED},
    {"braveWalletTransactionStatusSubmitted",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_SUBMITTED},
    {"braveWalletTransactionStatusConfirmed",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_CONFIRMED},
    {"braveWalletTransactionStatusError",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_ERROR},
    {"braveWalletTransactionStatusDropped",
     IDS_BRAVE_WALLET_TRANSACTION_STATUS_DROPPED},
    {"braveWalletRecentTransactions", IDS_BRAVE_WALLET_RECENT_TRANSACTIONS},
    {"braveWalletTransactionDetails", IDS_BRAVE_WALLET_TRANSACTION_DETAILS},
    {"braveWalletTransactionDetailDate",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_DATE},
    {"braveWalletTransactionDetailSpeedUp",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_SPEEDUP},
    {"braveWalletTransactionDetailHash",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_HASH},
    {"braveWalletTransactionDetailNetwork",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_NETWORK},
    {"braveWalletTransactionDetailStatus",
     IDS_BRAVE_WALLET_TRANSACTION_DETAIL_STATUS},
    {"braveWalletTransactionPlaceholder",
     IDS_BRAVE_WALLET_TRANSACTION_PLACEHOLDER},
    {"braveWalletTransactionApproveUnlimited",
     IDS_BRAVE_WALLET_TRANSACTION_APPROVE_UNLIMITED},
    {"braveWalletEditGasTitle1", IDS_BRAVE_WALLET_EDIT_GAS_TITLE1},
    {"braveWalletEditGasTitle2", IDS_BRAVE_WALLET_EDIT_GAS_TITLE2},
    {"braveWalletEditGasDescription", IDS_BRAVE_WALLET_EDIT_GAS_DESCRIPTION},
    {"braveWalletEditGasLow", IDS_BRAVE_WALLET_EDIT_GAS_LOW},
    {"braveWalletEditGasOptimal", IDS_BRAVE_WALLET_EDIT_GAS_OPTIMAL},
    {"braveWalletEditGasHigh", IDS_BRAVE_WALLET_EDIT_GAS_HIGH},
    {"braveWalletEditGasLimit", IDS_BRAVE_WALLET_EDIT_GAS_LIMIT},
    {"braveWalletEditGasPerGasPrice", IDS_BRAVE_WALLET_EDIT_GAS_PER_GAS_PRICE},
    {"braveWalletEditGasPerTipLimit", IDS_BRAVE_WALLET_EDIT_GAS_PER_TIP_LIMIT},
    {"braveWalletEditGasPerPriceLimit",
     IDS_BRAVE_WALLET_EDIT_GAS_PER_PRICE_LIMIT},
    {"braveWalletEditGasMaxFee", IDS_BRAVE_WALLET_EDIT_GAS_MAX_FEE},
    {"braveWalletEditGasMaximumFee", IDS_BRAVE_WALLET_EDIT_GAS_MAXIMUM_FEE},
    {"braveWalletEditGasBaseFee", IDS_BRAVE_WALLET_EDIT_GAS_BASE_FEE},
    {"braveWalletEditGasGwei", IDS_BRAVE_WALLET_EDIT_GAS_GWEI},
    {"braveWalletEditGasSetCustom", IDS_BRAVE_WALLET_EDIT_GAS_SET_CUSTOM},
    {"braveWalletEditGasSetSuggested", IDS_BRAVE_WALLET_EDIT_GAS_SET_SUGGESTED},
    {"braveWalletEditGasZeroGasPriceWarning",
     IDS_BRAVE_WALLET_EDIT_GAS_ZERO_GAS_PRICE_WARNING},
    {"braveWalletAdvancedTransactionSettings",
     IDS_BRAVE_WALLET_ADVANCED_TRANSACTION_SETTINGS},
    {"braveWalletAdvancedTransactionSettingsPlaceholder",
     IDS_BRAVE_WALLET_ADVANCED_TRANSACTION_SETTINGS_PLACEHOLDER},
    {"braveWalletEditNonce", IDS_BRAVE_WALLET_EDIT_NONCE},
    {"braveWalletEditNonceInfo", IDS_BRAVE_WALLET_EDIT_NONCE_INFO},
    {"braveWalletEditPermissionsTitle",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_TITLE},
    {"braveWalletEditPermissionsDescription",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_DESCRIPTION},
    {"braveWalletEditPermissionsButton",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_BUTTON},
    {"braveWalletEditPermissionsProposedAllowance",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_PROPOSED_ALLOWANCE},
    {"braveWalletEditPermissionsCustomAllowance",
     IDS_BRAVE_WALLET_EDIT_PERMISSIONS_CUSTOM_ALLOWANCE},
    {"braveWalletNotValidEthAddress", IDS_BRAVE_WALLET_NOT_VALID_ETH_ADDRESS},
    {"braveWalletNotValidSolAddress", IDS_BRAVE_WALLET_NOT_VALID_SOL_ADDRESS},
    {"braveWalletNotValidAddress", IDS_BRAVE_WALLET_NOT_VALID_ADDRESS},
    {"braveWalletNotDomain", IDS_BRAVE_WALLET_NOT_DOMAIN},
    {"braveWalletSameAddressError", IDS_BRAVE_WALLET_SAME_ADDRESS_ERROR},
    {"braveWalletContractAddressError",
     IDS_BRAVE_WALLET_CONTRACT_ADDRESS_ERROR},
    {"braveWalletAddressMissingChecksumInfoWarning",
     IDS_BRAVE_WALLET_ADDRESS_MISSING_CHECKSUM_INFO_WARNING},
    {"braveWalletNotValidChecksumAddressError",
     IDS_BRAVE_WALLET_NOT_VALID_CHECKSUM_ADDRESS_ERROR},
    {"braveWalletMissingGasLimitError",
     IDS_BRAVE_WALLET_MISSING_GAS_LIMIT_ERROR},
    {"braveWalletZeroBalanceError", IDS_BRAVE_WALLET_ZERO_BALANCE_ERROR},
    {"braveWalletAddressRequiredError",
     IDS_BRAVE_WALLET_ADDRESS_REQUIRED_ERROR},
    {"braveWalletQueueOf", IDS_BRAVE_WALLET_QUEUE_OF},
    {"braveWalletQueueNext", IDS_BRAVE_WALLET_QUEUE_NEXT},
    {"braveWalletQueueFirst", IDS_BRAVE_WALLET_QUEUE_FIRST},
    {"braveWalletQueueRejectAll", IDS_BRAVE_WALLET_QUEUE_REJECT_ALL},
    {"braveWalletSwapInsufficientBalance",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_BALANCE},
    {"braveWalletSwapInsufficientFundsForGas",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_FUNDS_FOR_GAS},
    {"braveWalletSwapInsufficientLiquidity",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_LIQUIDITY},
    {"braveWalletSwapInsufficientAllowance",
     IDS_BRAVE_WALLET_SWAP_INSUFFICIENT_ALLOWANCE},
    {"braveWalletSwapUnknownError", IDS_BRAVE_WALLET_SWAP_UNKNOWN_ERROR},
    {"braveWalletUnlockError", IDS_BRAVE_WALLET_UNLOCK_ERROR},
    {"braveWalletDeviceUnknownScheme", IDS_BRAVE_WALLET_UNKNOWN_SCHEME_ERROR},
    {"braveWalletApprovalTransactionIntent",
     IDS_BRAVE_WALLET_APPROVAL_TRANSACTION_INTENT},
    {"braveWalletLedgerFilecoinUnlockError",
     IDS_BRAVE_WALLET_LEDGER_FILECOIN_UNLOCK_ERROR},
    {"braveWalletLedgerValidationError",
     IDS_BRAVE_WALLET_LEDGER_VALIDATION_ERROR},
    {"braveWalletHardwareAccountNotFound",
     IDS_BRAVE_WALLET_HARDWARE_ACCOUNT_NOT_FOUND_ERROR},
    {"braveWalletCreateBridgeError",
     IDS_BRAVE_WALLET_HARDWARE_CREATE_BRIDGE_ERROR},
    {"braveWalletProcessTransactionError",
     IDS_BRAVE_WALLET_HARDWARE_PROCESS_TRANSACTION_ERROR},
    {"braveWalletApproveTransactionError",
     IDS_BRAVE_WALLET_HARDWARE_APPROVE_TRANSACTION_ERROR},
    {"braveWalletTransactionNotFoundSignError",
     IDS_BRAVE_WALLET_HARDWARE_TRANSACTION_NOT_FOUND_ERROR},
    {"braveWalletSignOnDeviceError",
     IDS_BRAVE_WALLET_HARDWARE_TRANSACTION_DEVICE_ERROR},
    {"braveWalletNoMessageToSignError",
     IDS_BRAVE_WALLET_HARDWARE_TRANSACTION_NO_MESSAGE_TO_SIGN_ERROR},
    {"braveWalletProcessMessageError",
     IDS_BRAVE_WALLET_HARDWARE_SIGN_MESSAGE_ERROR},
    {"braveWalletUnknownKeyringError",
     IDS_BRAVE_WALLET_HARDWARE_UNKNOWN_KEYRING_ERROR},
    {"braveWalletBridgeCommandInProgress",
     IDS_BRAVE_WALLET_HARDWARE_COMMAND_IN_PROGRESS_ERROR},
    {"braveWalletBridgeNotReady",
     IDS_BRAVE_WALLET_HARDWARE_BRIDGE_NOT_READY_ERROR},
    {"braveWalletAddSuggestedTokenTitle",
     IDS_BRAVE_WALLET_ADD_SUGGESTED_TOKEN_TITLE},
    {"braveWalletAddSuggestedTokenDescription",
     IDS_BRAVE_WALLET_ADD_SUGGESTED_TOKEN_DESCRIPTION},
    {"braveWalletNFTDetailBlockchain", IDS_BRAVE_WALLET_NFT_DETAIL_BLOCKCHAIN},
    {"braveWalletNFTDetailTokenStandard",
     IDS_BRAVE_WALLET_NFT_DETAIL_TOKEN_STANDARD},
    {"braveWalletNFTDetailTokenID", IDS_BRAVE_WALLET_NFT_DETAIL_TOKEN_ID},
    {"braveWalletTrezorSignTypedDataError",
     IDS_BRAVE_WALLET_TREZOR_SIGN_TYPED_DATA_ERROR},
    {"braveWalletSweepstakesTitle", IDS_BRAVE_WALLET_SWEEPSTAKES_TITLE},
    {"braveWalletSweepstakesDescription",
     IDS_BRAVE_WALLET_SWEEPSTAKES_DESCRIPTION},
    {"braveWalletSweepstakesCallToAction",
     IDS_BRAVE_WALLET_SWEEPSTAKES_CALL_TO_ACTION},
    {"braveWalletNotValidFilAddress", IDS_BRAVE_WALLET_NOT_VALID_FIL_ADDRESS},
    {"braveWalletBuyWithWyre", IDS_BRAVE_WALLET_BUY_WITH_WYRE},
    {"braveWalletBuyWithRamp", IDS_BRAVE_WALLET_BUY_WITH_RAMP},
    {"braveWalletBuyRampNetworkName", IDS_BRAVE_WALLET_BUY_RAMP_NETWORK_NAME},
    {"braveWalletBuyWyreName", IDS_BRAVE_WALLET_BUY_WYRE_NAME},
    {"braveWalletBuyRampDescription", IDS_BRAVE_WALLET_BUY_RAMP_DESCRIPTION},
    {"braveWalletBuyWyreDescription", IDS_BRAVE_WALLET_BUY_WYRE_DESCRIPTION},
    {"braveWalletNetworkFilterAll", IDS_BRAVE_WALLET_NETWORK_FILTER_ALL},
    {"braveWalletEditGasLimitError", IDS_BRAVE_WALLET_EDIT_GAS_LIMIT_ERROR},
    {"braveWalletApproveTransaction", IDS_BRAVE_WALLET_APPROVE_TRANSACTION},
    {"braveWalletSolanaSystemProgram", IDS_BRAVE_WALLET_SOLANA_SYSTEM_PROGRAM},
    {"braveWalletSolanaConfigProgram", IDS_BRAVE_WALLET_SOLANA_CONFIG_PROGRAM},
    {"braveWalletSolanaStakeProgram", IDS_BRAVE_WALLET_SOLANA_STAKE_PROGRAM},
    {"braveWalletSolanaVoteProgram", IDS_BRAVE_WALLET_SOLANA_VOTE_PROGRAM},
    {"braveWalletSolanaBPFLoader", IDS_BRAVE_WALLET_SOLANA_BP_FLOADER},
    {"braveWalletSolanaParamKeyFromPubkey",
     IDS_BRAVE_WALLET_SOLANA_PARAM_KEY_FROMPUBKEY},
    {"braveWalletSolanaParamKeyToPubkey",
     IDS_BRAVE_WALLET_SOLANA_PARAM_KEY_TOPUBKEY},
    {"braveWalletSolanaParamKeyLamports",
     IDS_BRAVE_WALLET_SOLANA_PARAM_KEY_LAMPORTS},
    {"braveWalletSolanaParamKeyNewAccountPubkey",
     IDS_BRAVE_WALLET_SOLANA_PARAM_KEY_NEWACCOUNTPUBKEY},
    {"braveWalletSolanaEd25519Program",
     IDS_BRAVE_WALLET_SOLANA_ED25519_PROGRAM},
    {"braveWalletSolanaSecp256k1Program",
     IDS_BRAVE_WALLET_SOLANA_SECP256K1_PROGRAM},
    {"braveWalletNetworkFilterSecondary",
     IDS_BRAVE_WALLET_NETWORK_FILTER_SECONDARY}};

// Swap constants
constexpr char kRopstenSwapBaseAPIURL[] = "https://ropsten.api.0x.org/";
// As of 22-02-2022, this address is controlled by @onyb.
constexpr char kRopstenFeeRecipient[] =
    "0xa92D461a9a988A7f11ec285d39783A637Fdd6ba4";
constexpr char kPolygonSwapBaseAPIURL[] = "https://polygon.api.0x.org/";
constexpr char kBinanceSmartChainSwapBaseAPIURL[] = "https://bsc.api.0x.org/";
constexpr char kAvalancheSwapBaseAPIURL[] = "https://avalanche.api.0x.org/";
constexpr char kFantomSwapBaseAPIURL[] = "https://fantom.api.0x.org/";
constexpr char kCeloSwapBaseAPIURL[] = "https://celo.api.0x.org/";
constexpr char kOptimismSwapBaseAPIURL[] = "https://optimism.api.0x.org/";
constexpr char kSwapBaseAPIURL[] = "https://api.0x.org/";
constexpr char kBuyTokenPercentageFee[] = "0.00875";
constexpr char kFeeRecipient[] = "0xbd9420A98a7Bd6B89765e5715e169481602D9c3d";
constexpr char kAffiliateAddress[] =
    "0xbd9420A98a7Bd6B89765e5715e169481602D9c3d";

constexpr int64_t kBlockTrackerDefaultTimeInSeconds = 20;

constexpr char kPolygonMainnetEndpoint[] = "https://mainnet-polygon.brave.com/";

// Unstoppable domains record key for ethereum address.
constexpr char kCryptoEthAddressKey[] = "crypto.ETH.address";

// ERC-165 identifier for ERC721 interface.
constexpr char kERC1155InterfaceId[] = "0xd9b67a26";
constexpr char kERC1155MetadataInterfaceId[] = "0x0e89341c";
constexpr char kERC721InterfaceId[] = "0x80ac58cd";
constexpr char kERC721MetadataInterfaceId[] = "0x5b5e139f";

constexpr char kEthereumPrefKey[] = "ethereum";
constexpr char kFilecoinPrefKey[] = "filecoin";
constexpr char kSolanaPrefKey[] = "solana";

const std::vector<mojom::BlockchainToken>& GetWyreBuyTokens();
const std::vector<mojom::BlockchainToken>& GetRampBuyTokens();

}  // namespace brave_wallet

#endif  // BRAVE_COMPONENTS_BRAVE_WALLET_BROWSER_BRAVE_WALLET_CONSTANTS_H_
