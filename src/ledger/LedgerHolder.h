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

#ifndef SKYWELL_APP_LEDGER_LEDGERHOLDER_H_INCLUDED
#define SKYWELL_APP_LEDGER_LEDGERHOLDER_H_INCLUDED

namespace truechain {

// Can std::atomic<std::shared_ptr>> make this lock free?

/** Hold a ledger in a thread-safe way.
*/
class LedgerHolder
{
public:
    typedef SkywellMutex LockType;
    typedef std::lock_guard <LockType> ScopedLockType;

    // Update the held ledger
    void set (Ledger::pointer ledger)
    {
        // The held ledger must always be immutable
        if (ledger && !ledger->isImmutable ())
           ledger = std::make_shared <Ledger> (*ledger, false);

        {
            ScopedLockType sl (m_lock);

            m_heldLedger = ledger;
        }
    }

    // Return the (immutable) held ledger
    Ledger::pointer get ()
    {
        ScopedLockType sl (m_lock);

        return m_heldLedger;
    }

    // Return a mutable snapshot of the held ledger
    Ledger::pointer getMutable ()
    {
        Ledger::pointer ret = get ();
        return ret ? std::make_shared <Ledger> (*ret, true) : ret;
    }


    bool empty ()
    {
        ScopedLockType sl (m_lock);

        return m_heldLedger == nullptr;
    }

private:

    LockType m_lock;
    Ledger::pointer m_heldLedger;

};

} // truechain

#endif
