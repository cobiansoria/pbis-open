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
 * Module Name:
 *
 *        security-private.h
 *
 * Abstract:
 *
 *        Security token API (private header)
 *
 * Authors: Brian Koropoff (bkoropoff@likewisesoftware.com)
 *
 */
#ifndef __LWMSG_SECURITY_PRIVATE_H__
#define __LWMSG_SECURITY_PRIVATE_H__

#include <lwmsg/security.h>
#include <lwmsg/buffer.h>

typedef struct LWMsgSecurityTokenClass
{
    /** The size of the private data structure used by the implementation */
    size_t private_size;
    /**
     * @ingroup security_impl
     * @brief Construct method
     *
     * Performs basic construction of a new security token.
     *
     * @param token the token object
     * @lwmsg_status
     * @lwmsg_success
     * @lwmsg_memory
     * @lwmsg_endstatus
     */
    LWMsgStatus (*construct)(LWMsgSecurityToken* token);
    /**
     * @ingroup security_impl
     * @brief Destruct method
     *
     * Frees all resources allocated by the construct method.
     *
     * @param token the token object
     */
    void (*destruct)(LWMsgSecurityToken* token);
    /**
     * @ingroup security_impl
     * @brief Query token type method
     *
     * Returns the string constant which identifies the
     * type of the security token.
     * @param token the token object
     * @return the string constant identifier
     */
    const char* (*get_type)(LWMsgSecurityToken* token);
    /**
     * @ingroup security_impl
     * @brief Compare token method
     *
     * Compares two security tokens for equality
     *
     * @param token the token on which the method was dispatched
     * @param other the other security token
     * @retval #LWMSG_TRUE if the tokens are equal
     * @retval #LWMSG_FALSE if the tokens are not equal
     */
    LWMsgBool (*equal)(LWMsgSecurityToken* token, LWMsgSecurityToken* other);
    /**
     * @ingroup security_impl
     * @brief Test access permission method
     *
     * Tests if the security token <tt>other</tt> is allowed to
     * access resources owned by the security token <tt>token</tt>.
     * This method must return #LWMSG_TRUE in all cases where
     * the equal method would do so.
     *
     * @param token the token on which the method was dispatched
     * @param other the other security token
     * @retval #LWMSG_TRUE <tt>other</tt> can access resources owned by <tt>token</tt>
     * @retval #LWMSG_FALSE <tt>other</tt> cannot access resources owned by <tt>token</tt>
     */
    LWMsgBool (*can_access)(LWMsgSecurityToken* token, LWMsgSecurityToken* other);
    /**
     * @ingroup security_impl
     * @brief Copy method
     *
     * Creates an identical copy of the security token.  In particular,
     * the following invariants must be satisfied after the method completes:
     *
     * - <tt>token != *out_token</tt>
     * - <tt>lwmsg_security_token_equal(token, *out_token) == LWMSG_TRUE</tt>
     *
     * @param[in] token the token object
     * @param[out] out_token the copy
     * @lwmsg_status
     * @lwmsg_success
     * @lwmsg_memory
     * @lwmsg_endstatus
     */
    LWMsgStatus (*copy)(LWMsgSecurityToken* token, LWMsgSecurityToken** out_token);
    /**
     * @ingroup security_impl
     * @brief Hash method
     *
     * Returns a hash code for a security token.  A good implementation of this
     * method is important for client applications which may want to perform
     * efficient lookups into a data structure with a security token key.
     *
     * The following invariants must be satisfied for any two tokens <tt>a</tt>
     * and <tt>b</tt>.
     *
     * - If equal(a, b) == LWMSG_TRUE, then hash(a) == hash(b)
     * - If hash(a) != hash(b), then equal(a,b) == LWMSG_FALSE
     * @param token the token object
     * @return a hash code
     */
    size_t (*hash)(LWMsgSecurityToken* token);
    LWMsgStatus (*to_string)(LWMsgSecurityToken* token, LWMsgBuffer* buffer);
} LWMsgSecurityTokenClass;

/**
 * @ingroup security_impl
 * @brief Instantiate security token
 *
 * Creates a new security token of the specified class and
 * calls the constructor.  This function should generally
 * not be used by client applications directly.
 *
 * @param[in] tclass the token class structure
 * @param[out] token the created token
 * @lwmsg_status
 * @lwmsg_success
 * @lwmsg_memory
 * @lwmsg_endstatus
 */
LWMsgStatus
lwmsg_security_token_new(
    LWMsgSecurityTokenClass* tclass,
    LWMsgSecurityToken** token
    );

/**
 * @ingroup security_impl
 * @brief Access private data
 *
 * Gets the private data structure for the specified
 * token.  This function should generally not be used
 * by client applications directly.
 *
 * @param[in] token the token object
 * @return a pointer to the private data structure
 */
void*
lwmsg_security_token_get_private(
    LWMsgSecurityToken* token
    );

LWMsgStatus
lwmsg_security_token_to_string(
    LWMsgSecurityToken* token,
    LWMsgBuffer* buffer
    );

struct LWMsgSecurityToken
{
    LWMsgSecurityTokenClass* tclass;
    
    unsigned char private_data[];
};

#endif
