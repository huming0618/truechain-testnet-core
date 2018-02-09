//------------------------------------------------------------------------------
/*
    This file is part of skywelld: https://github.com/skywell/skywelld
    Copyright (c) 2012-2014 Skywell Labs Inc.

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
#include <ledger/LedgerToJson.h>
#include <services/rpc/impl/LookupLedger.h>
#include <services/rpc/Context.h>
#include <protocol/JsonFields.h>

namespace truechain {

// {
//   ledger_hash : <ledger>
//   ledger_index : <ledger_index>
// }
Json::Value doLedgerHeader (RPC::Context& context)
{
    Ledger::pointer lpLedger;
    Json::Value jvResult = RPC::lookupLedger (
        context.params, lpLedger, context.netOps);

    if (!lpLedger)
        return jvResult;

    Serializer  s;

    lpLedger->addRaw (s);

    jvResult[jss::ledger_data] = strHex (s.peekData ());

    // This information isn't verified: they should only use it if they trust
    // us.
    addJson (jvResult, {*lpLedger, 0});

    return jvResult;
}


} // truechain