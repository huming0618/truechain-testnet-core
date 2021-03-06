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
#include <beast/utility/static_initializer.h>
#include <protocol/TxFormats.h>

namespace truechain {

TxFormats::TxFormats ()
{
    add ("AccountSet", ttACCOUNT_SET)
        << SOElement (sfEmailHash,           SOE_OPTIONAL)
        << SOElement (sfWalletLocator,       SOE_OPTIONAL)
        << SOElement (sfWalletSize,          SOE_OPTIONAL)
        << SOElement (sfMessageKey,          SOE_OPTIONAL)
        << SOElement (sfDomain,              SOE_OPTIONAL)
        << SOElement (sfTransferRate,        SOE_OPTIONAL)
        << SOElement (sfSetFlag,             SOE_OPTIONAL)
        << SOElement (sfClearFlag,           SOE_OPTIONAL)
        << SOElement (sfNickname,            SOE_OPTIONAL)
        << SOElement (sfCurrencyRates,       SOE_OPTIONAL)
        ;

    add ("TrustSet", ttTRUST_SET)
        << SOElement (sfLimitAmount,         SOE_OPTIONAL)
        << SOElement (sfQualityIn,           SOE_OPTIONAL)
        << SOElement (sfQualityOut,          SOE_OPTIONAL)
        ;

    add ("RelationSet", ttREL_SET)
        << SOElement (sfTarget,              SOE_REQUIRED)
        << SOElement (sfRelationType,       SOE_REQUIRED)
        << SOElement (sfLimitAmount,        SOE_OPTIONAL)
        ;
	
    add ("RelationDel", ttREL_DEL)
        << SOElement (sfTarget,              SOE_REQUIRED)
        << SOElement (sfRelationType,       SOE_REQUIRED)
        << SOElement (sfLimitAmount,         SOE_OPTIONAL)
        ;

    

    add ("SetRegularKey", ttREGULAR_KEY_SET)
        << SOElement (sfRegularKey,          SOE_OPTIONAL)
        ;

    add ("Payment", ttPAYMENT)
        << SOElement (sfDestination,         SOE_REQUIRED)
        << SOElement (sfAmount,              SOE_REQUIRED)
        << SOElement (sfSendMax,             SOE_OPTIONAL)
        << SOElement (sfPaths,               SOE_DEFAULT)
        << SOElement (sfInvoiceID,           SOE_OPTIONAL)
        << SOElement (sfDestinationTag,      SOE_OPTIONAL)
        ;

    add ("EnableAmendment", ttAMENDMENT)
        << SOElement (sfLedgerSequence,      SOE_OPTIONAL)
        << SOElement (sfAmendment,           SOE_REQUIRED)
        ;

    add ("SetFee", ttFEE)
        << SOElement (sfLedgerSequence,      SOE_OPTIONAL)
        << SOElement (sfBaseFee,             SOE_REQUIRED)
        << SOElement (sfReferenceFeeUnits,   SOE_REQUIRED)
        << SOElement (sfReserveBase,         SOE_REQUIRED)
        << SOElement (sfReserveIncrement,    SOE_REQUIRED)
        ;

    add ("TicketCreate", ttTICKET_CREATE)
        << SOElement (sfTarget,              SOE_OPTIONAL)
        << SOElement (sfExpiration,          SOE_OPTIONAL)
        ;

    add ("TicketCancel", ttTICKET_CANCEL)
        << SOElement (sfTicketID,            SOE_REQUIRED)
        ;
	
    add ("ManageFee", ttMNGFEE)
        << SOElement (sfFeeAccountID,    SOE_REQUIRED)
        ;
    add ("ManageIssuer", ttMNGISSUER)
        << SOElement (sfIssuerAccountID,    SOE_REQUIRED)
        ;
    add ("SetBlackList", ttBLKLISTSET)
        << SOElement (sfBlackListAccountID,    SOE_REQUIRED)
        ;
    add ("RemoveBlackList", ttBLKLISTRMV)
        << SOElement (sfBlackListAccountID,    SOE_REQUIRED)
        ;
    add ("AccountMerge", ttACCOUNT_MERGE)
        << SOElement (sfDestination,         SOE_REQUIRED)
        ;

    add("Operation", ttOPERATION)
        << SOElement (sfOperations, SOE_REQUIRED)
        << SOElement (sfSigns, SOE_OPTIONAL)
        ;   

	add("SignSet", ttSIGN_SET)
		//<< SOElement(sfTarget, SOE_REQUIRED)
		<< SOElement(sfMasterWeight, SOE_OPTIONAL)
		<< SOElement(sfQuorum, SOE_OPTIONAL)
		<< SOElement(sfQuorumHigh, SOE_OPTIONAL)
		<< SOElement(sfSignerEntries, SOE_OPTIONAL)
		;
	add("NicknameSet", ttNICKNAME_SET)
		<< SOElement(sfDomain, SOE_OPTIONAL)
		<< SOElement(sfNickname, SOE_OPTIONAL)
		;

    add("Message", ttMESSAGE)
        << SOElement(sfDestination, SOE_REQUIRED)
	    << SOElement(sfMessageHash, SOE_OPTIONAL)
		;
}

void TxFormats::addCommonFields (Item& item)
{
    item
        << SOElement(sfTransactionType,     SOE_REQUIRED)
        << SOElement(sfFlags,               SOE_OPTIONAL)
        << SOElement(sfTimestamp,           SOE_OPTIONAL)
        << SOElement(sfSourceTag,           SOE_OPTIONAL)
        << SOElement(sfAccount,             SOE_REQUIRED)
        << SOElement(sfSequence,            SOE_OPTIONAL/*SOE_REQUIRED*/)
        << SOElement(sfPreviousTxnID,       SOE_OPTIONAL) // emulate027
        << SOElement(sfLastLedgerSequence,  SOE_OPTIONAL)
        << SOElement(sfAccountTxnID,        SOE_OPTIONAL)
        << SOElement(sfFee,                 SOE_OPTIONAL/*SOE_REQUIRED*/)
        << SOElement(sfOperationLimit,      SOE_OPTIONAL)
        << SOElement(sfMemos,               SOE_OPTIONAL)
        << SOElement(sfSigningPubKey,       SOE_OPTIONAL/*SOE_REQUIRED*/)
        << SOElement(sfTxnSignature,        SOE_OPTIONAL)
        ;
}

TxFormats const&
TxFormats::getInstance ()
{
    static beast::static_initializer<
        TxFormats> instance;
    return *instance;
}

} // truechain
