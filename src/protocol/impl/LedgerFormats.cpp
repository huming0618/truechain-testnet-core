//------------------------------------------------------------------------------
/*
	Copyright (c) 2012, 2013 Skywell Labs Inc.
	Copyright (c) 2017-2018 TrueChain Foundation.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#include <BeastConfig.h>
#include <protocol/LedgerFormats.h>

namespace truechain {

LedgerFormats::LedgerFormats ()
{
    add ("AccountRoot", ltACCOUNT_ROOT)
            << SOElement (sfAccount,             SOE_REQUIRED)
            << SOElement (sfSequence,            SOE_REQUIRED)
            << SOElement (sfBalance,             SOE_REQUIRED)
            << SOElement (sfOwnerCount,          SOE_REQUIRED)
            << SOElement (sfPreviousTxnID,       SOE_REQUIRED)
            << SOElement (sfPreviousTxnLgrSeq,   SOE_REQUIRED)
            << SOElement (sfAccountTxnID,        SOE_OPTIONAL)
            << SOElement (sfRegularKey,          SOE_OPTIONAL)
            << SOElement (sfEmailHash,           SOE_OPTIONAL)
            << SOElement (sfWalletLocator,       SOE_OPTIONAL)
            << SOElement (sfWalletSize,          SOE_OPTIONAL)
            << SOElement (sfMessageKey,          SOE_OPTIONAL)
            << SOElement (sfTransferRate,        SOE_OPTIONAL)
            << SOElement (sfDomain,              SOE_OPTIONAL)
            << SOElement(sfNickname,             SOE_OPTIONAL)
            << SOElement(sfCurrencyRates,        SOE_OPTIONAL)
            ;

    add ("DirectoryNode", ltDIR_NODE)
            << SOElement (sfOwner,               SOE_OPTIONAL)  // for owner directories
            << SOElement (sfTakerPaysCurrency,   SOE_OPTIONAL)  // for order book directories
            << SOElement (sfTakerPaysIssuer,     SOE_OPTIONAL)  // for order book directories
            << SOElement (sfTakerGetsCurrency,   SOE_OPTIONAL)  // for order book directories
            << SOElement (sfTakerGetsIssuer,     SOE_OPTIONAL)  // for order book directories
            << SOElement (sfExchangeRate,        SOE_OPTIONAL)  // for order book directories
            << SOElement (sfIndexes,             SOE_REQUIRED)
            << SOElement (sfRootIndex,           SOE_REQUIRED)
            << SOElement (sfIndexNext,           SOE_OPTIONAL)
            << SOElement (sfIndexPrevious,       SOE_OPTIONAL)
            ;

    add ("Offer", ltOFFER)
            << SOElement (sfAccount,             SOE_REQUIRED)
            << SOElement (sfSequence,            SOE_REQUIRED)
            << SOElement (sfTakerPays,           SOE_REQUIRED)
            << SOElement (sfTakerGets,           SOE_REQUIRED)
            << SOElement (sfBookDirectory,       SOE_REQUIRED)
            << SOElement (sfBookNode,            SOE_REQUIRED)
            << SOElement (sfOwnerNode,           SOE_REQUIRED)
            << SOElement (sfPreviousTxnID,       SOE_REQUIRED)
            << SOElement (sfPreviousTxnLgrSeq,   SOE_REQUIRED)
            << SOElement (sfExpiration,          SOE_OPTIONAL)
            ;

    add ("SkywellState", ltSKYWELL_STATE)
            << SOElement (sfBalance,             SOE_REQUIRED)
            << SOElement (sfLowLimit,            SOE_REQUIRED)
            << SOElement (sfHighLimit,           SOE_REQUIRED)
            << SOElement (sfPreviousTxnID,       SOE_REQUIRED)
            << SOElement (sfPreviousTxnLgrSeq,   SOE_REQUIRED)
            << SOElement (sfLowNode,             SOE_OPTIONAL)
            << SOElement (sfLowQualityIn,        SOE_OPTIONAL)
            << SOElement (sfLowQualityOut,       SOE_OPTIONAL)
            << SOElement (sfHighNode,            SOE_OPTIONAL)
            << SOElement (sfHighQualityIn,       SOE_OPTIONAL)
            << SOElement (sfHighQualityOut,      SOE_OPTIONAL)
            ;

    add ("TrustState", ltTrust_STATE)
            << SOElement (sfBalance,             SOE_REQUIRED)
            << SOElement (sfRelationType,             SOE_OPTIONAL)            
            << SOElement (sfLowLimit,            SOE_REQUIRED)
            << SOElement (sfHighLimit,           SOE_REQUIRED)
            << SOElement (sfLowNode,             SOE_OPTIONAL)
            << SOElement (sfLowQualityIn,        SOE_OPTIONAL)
            << SOElement (sfLowQualityOut,       SOE_OPTIONAL)
            << SOElement (sfHighNode,            SOE_OPTIONAL)
            << SOElement (sfHighQualityIn,       SOE_OPTIONAL)
            << SOElement (sfHighQualityOut,      SOE_OPTIONAL)
            ;

    add ("LedgerHashes", ltLEDGER_HASHES)
            << SOElement (sfFirstLedgerSequence, SOE_OPTIONAL) // Remove if we do a ledger restart
            << SOElement (sfLastLedgerSequence,  SOE_OPTIONAL)
            << SOElement (sfHashes,              SOE_REQUIRED)
            ;

    add ("EnabledAmendments", ltAMENDMENTS)
            << SOElement (sfAmendments, SOE_REQUIRED)
            ;

    add ("FeeSettings", ltFEE_SETTINGS)
            << SOElement (sfBaseFee,             SOE_REQUIRED)
            << SOElement (sfReferenceFeeUnits,   SOE_REQUIRED)
            << SOElement (sfReserveBase,         SOE_REQUIRED)
            << SOElement (sfReserveIncrement,    SOE_REQUIRED)
            ;

    add ("Ticket", ltTICKET)
            << SOElement (sfAccount,             SOE_REQUIRED)
            << SOElement (sfSequence,            SOE_REQUIRED)
            << SOElement (sfOwnerNode,           SOE_REQUIRED)
            << SOElement (sfTarget,              SOE_OPTIONAL)
            << SOElement (sfExpiration,          SOE_OPTIONAL)
            ;
	
    add ("ManageFee", ltMANAGE_FEE)
            << SOElement (sfFeeAccountID,    SOE_REQUIRED)
            ;
	
    add ("ManageIssuer", ltMANAGE_ISSUER)
            << SOElement (sfIssuerAccountID,    SOE_REQUIRED)
            ;
	
    add ("BlackList", ltBLACKLIST)
            << SOElement (sfBlackListAccountID,    SOE_REQUIRED)
            ;

	add("SignerList", ltSIGNER_LIST)
		<< SOElement(sfAccount, SOE_REQUIRED)
		<< SOElement(sfMasterWeight, SOE_REQUIRED)
		<< SOElement(sfQuorum, SOE_REQUIRED)
		<< SOElement(sfQuorumHigh, SOE_REQUIRED)
		<< SOElement(sfSignerEntries, SOE_REQUIRED)
        ;
	add("Nickname", ltNICKNAME)
		<< SOElement(sfAccount, SOE_REQUIRED)
		<< SOElement(sfDomain, SOE_OPTIONAL)
		<< SOElement(sfNickname, SOE_OPTIONAL)
		;
}

void LedgerFormats::addCommonFields (Item& item)
{
				item
        << SOElement(sfLedgerIndex,             SOE_OPTIONAL)
        << SOElement(sfLedgerEntryType,         SOE_REQUIRED)
        << SOElement(sfFlags,                   SOE_REQUIRED)
        ;
}

LedgerFormats const&
LedgerFormats::getInstance ()
{
    static LedgerFormats instance;
    return instance;
}

} // truechain