//
//  tests_keys.h
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#ifndef ___LIBUSHER_TESTS_KEYS_H___
#define ___LIBUSHER_TESTS_KEYS_H___

#include "tests.h"

static const testdata_t GITHUB_API[142] = {
    { 
        .path = "/applications/:client_id/tokens/:access_token", 
        .key = "/applications/client_id/tokens/access_token", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":client_id",
                    (uint8_t*)"client_id"
                },
                {
                    (uint8_t*)":access_token",
                    (uint8_t*)"access_token"
                }
            }
        }
    },
    { 
        .path = "/authorizations/", 
        .key = "/authorizations/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/authorizations/:id", 
        .key = "/authorizations/id", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/emojis", 
        .key = "/emojis", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/events", 
        .key = "/events", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/feeds", 
        .key = "/feeds", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gists/", 
        .key = "/gists/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gists/:id/", 
        .key = "/gists/id/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/gists/:id/star", 
        .key = "/gists/id/star", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/gists/public", 
        .key = "/gists/public", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gists/starred", 
        .key = "/gists/starred", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gitignore/templates/", 
        .key = "/gitignore/templates/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gitignore/templates/:name", 
        .key = "/gitignore/templates/name", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":name",
                    (uint8_t*)"name"
                }
            }
        }
    },
    { 
        .path = "/issues", 
        .key = "/issues", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/legacy/issues/search/:owner/:repository/:state/:keyword", 
        .key = "/legacy/issues/search/owner/repository/state/keyword", 
        { 
            .nitems = 4,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repository",
                    (uint8_t*)"repository"
                },
                {
                    (uint8_t*)":state",
                    (uint8_t*)"state"
                },
                {
                    (uint8_t*)":keyword",
                    (uint8_t*)"keyword"
                }
            }
        }
    },
    { 
        .path = "/legacy/repos/search/:keyword", 
        .key = "/legacy/repos/search/keyword", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":keyword",
                    (uint8_t*)"keyword"
                }
            }
        }
    },
    { 
        .path = "/legacy/user/email/:email", 
        .key = "/legacy/user/email/email", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":email",
                    (uint8_t*)"email"
                }
            }
        }
    },
    { 
        .path = "/legacy/user/search/:keyword", 
        .key = "/legacy/user/search/keyword", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":keyword",
                    (uint8_t*)"keyword"
                }
            }
        }
    },
    { 
        .path = "/meta", 
        .key = "/meta", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/networks/:owner/:repo/events", 
        .key = "/networks/owner/repo/events", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/notifications/", 
        .key = "/notifications/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/notifications/threads/:id/", 
        .key = "/notifications/threads/id/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/notifications/threads/:id/subscription", 
        .key = "/notifications/threads/id/subscription", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/", 
        .key = "/orgs/org/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/events", 
        .key = "/orgs/org/events", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/issues", 
        .key = "/orgs/org/issues", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/members/", 
        .key = "/orgs/org/members/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/members/:user", 
        .key = "/orgs/org/members/user", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                },
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/public_members/", 
        .key = "/orgs/org/public_members/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/public_members/:user", 
        .key = "/orgs/org/public_members/user", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                },
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/repos", 
        .key = "/orgs/org/repos", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/orgs/:org/teams", 
        .key = "/orgs/org/teams", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/rate_limit", 
        .key = "/rate_limit", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/repos/:owner/:repo/", 
        .key = "/repos/owner/repo/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/:archive_format/:ref", 
        .key = "/repos/owner/repo/archive_format/ref", 
        { 
            .nitems = 4,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":archive_format",
                    (uint8_t*)"archive_format"
                },
                {
                    (uint8_t*)":ref",
                    (uint8_t*)"ref"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/assignees/", 
        .key = "/repos/owner/repo/assignees/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/assignees/:assignee", 
        .key = "/repos/owner/repo/assignees/assignee", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":assignee",
                    (uint8_t*)"assignee"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/branches/", 
        .key = "/repos/owner/repo/branches/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/branches/:branch", 
        .key = "/repos/owner/repo/branches/branch", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":branch",
                    (uint8_t*)"branch"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/collaborators/", 
        .key = "/repos/owner/repo/collaborators/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/collaborators/:user", 
        .key = "/repos/owner/repo/collaborators/user", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/comments/", 
        .key = "/repos/owner/repo/comments/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/comments/:id", 
        .key = "/repos/owner/repo/comments/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/commits/", 
        .key = "/repos/owner/repo/commits/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/commits/:sha/", 
        .key = "/repos/owner/repo/commits/sha/", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/commits/:sha/comments", 
        .key = "/repos/owner/repo/commits/sha/comments", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/contents/*path", 
        .key = "/repos/owner/repo/contents/*path", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/contributors", 
        .key = "/repos/owner/repo/contributors", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/downloads/", 
        .key = "/repos/owner/repo/downloads/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/downloads/:id", 
        .key = "/repos/owner/repo/downloads/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/events", 
        .key = "/repos/owner/repo/events", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/forks", 
        .key = "/repos/owner/repo/forks", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/blobs/:sha", 
        .key = "/repos/owner/repo/git/blobs/sha", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/commits/:sha", 
        .key = "/repos/owner/repo/git/commits/sha", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/refs", 
        .key = "/repos/owner/repo/git/refs", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/refs/*ref", 
        .key = "/repos/owner/repo/git/refs/*ref", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/tags/:sha", 
        .key = "/repos/owner/repo/git/tags/sha", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/git/trees/:sha", 
        .key = "/repos/owner/repo/git/trees/sha", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":sha",
                    (uint8_t*)"sha"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/hooks/", 
        .key = "/repos/owner/repo/hooks/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/hooks/:id", 
        .key = "/repos/owner/repo/hooks/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/", 
        .key = "/repos/owner/repo/issues/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/:number/", 
        .key = "/repos/owner/repo/issues/number/", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/:number/comments", 
        .key = "/repos/owner/repo/issues/number/comments", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/:number/events", 
        .key = "/repos/owner/repo/issues/number/events", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/:number/labels", 
        .key = "/repos/owner/repo/issues/number/labels", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/comments", 
        .key = "/repos/owner/repo/issues/comments", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/comments/:id", 
        .key = "/repos/owner/repo/issues/comments/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/events", 
        .key = "/repos/owner/repo/issues/events", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/issues/events/:id", 
        .key = "/repos/owner/repo/issues/events/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/keys/", 
        .key = "/repos/owner/repo/keys/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/keys/:id", 
        .key = "/repos/owner/repo/keys/id", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/labels/", 
        .key = "/repos/owner/repo/labels/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/labels/:name", 
        .key = "/repos/owner/repo/labels/name", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":name",
                    (uint8_t*)"name"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/languages", 
        .key = "/repos/owner/repo/languages", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/milestones/", 
        .key = "/repos/owner/repo/milestones/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/milestones/:number/", 
        .key = "/repos/owner/repo/milestones/number/", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/milestones/:number/labels", 
        .key = "/repos/owner/repo/milestones/number/labels", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/notifications", 
        .key = "/repos/owner/repo/notifications", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/", 
        .key = "/repos/owner/repo/pulls/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/:number/", 
        .key = "/repos/owner/repo/pulls/number/", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/:number/comments", 
        .key = "/repos/owner/repo/pulls/number/comments", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/:number/commits", 
        .key = "/repos/owner/repo/pulls/number/commits", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/:number/files", 
        .key = "/repos/owner/repo/pulls/number/files", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/:number/merge", 
        .key = "/repos/owner/repo/pulls/number/merge", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/comments", 
        .key = "/repos/owner/repo/pulls/comments", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/pulls/comments/:number", 
        .key = "/repos/owner/repo/pulls/comments/number", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":number",
                    (uint8_t*)"number"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/readme", 
        .key = "/repos/owner/repo/readme", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/releases/", 
        .key = "/repos/owner/repo/releases/", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/releases/:id/", 
        .key = "/repos/owner/repo/releases/id/", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/releases/:id/assets", 
        .key = "/repos/owner/repo/releases/id/assets", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stargazers", 
        .key = "/repos/owner/repo/stargazers", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stats/code_frequency", 
        .key = "/repos/owner/repo/stats/code_frequency", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stats/commit_activity", 
        .key = "/repos/owner/repo/stats/commit_activity", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stats/contributors", 
        .key = "/repos/owner/repo/stats/contributors", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stats/participation", 
        .key = "/repos/owner/repo/stats/participation", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/stats/punch_card", 
        .key = "/repos/owner/repo/stats/punch_card", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/statuses/:ref", 
        .key = "/repos/owner/repo/statuses/ref", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                },
                {
                    (uint8_t*)":ref",
                    (uint8_t*)"ref"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/subscribers", 
        .key = "/repos/owner/repo/subscribers", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/subscription", 
        .key = "/repos/owner/repo/subscription", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/tags", 
        .key = "/repos/owner/repo/tags", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repos/:owner/:repo/teams", 
        .key = "/repos/owner/repo/teams", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/repositories", 
        .key = "/repositories", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/search/code", 
        .key = "/search/code", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/search/issues", 
        .key = "/search/issues", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/search/repositories", 
        .key = "/search/repositories", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/search/users", 
        .key = "/search/users", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/teams/:id/", 
        .key = "/teams/id/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/teams/:id/members/", 
        .key = "/teams/id/members/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/teams/:id/members/:user", 
        .key = "/teams/id/members/user", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                },
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/teams/:id/repos/", 
        .key = "/teams/id/repos/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/teams/:id/repos/:owner/:repo", 
        .key = "/teams/id/repos/owner/repo", 
        { 
            .nitems = 3,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                },
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/user/", 
        .key = "/user/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/emails", 
        .key = "/user/emails", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/followers", 
        .key = "/user/followers", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/following/", 
        .key = "/user/following/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/following/:user", 
        .key = "/user/following/user", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/user/issues", 
        .key = "/user/issues", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/keys/", 
        .key = "/user/keys/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/keys/:id", 
        .key = "/user/keys/id", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":id",
                    (uint8_t*)"id"
                }
            }
        }
    },
    { 
        .path = "/user/orgs", 
        .key = "/user/orgs", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/repos", 
        .key = "/user/repos", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/starred/", 
        .key = "/user/starred/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/starred/:owner/:repo", 
        .key = "/user/starred/owner/repo", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/user/subscriptions/", 
        .key = "/user/subscriptions/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/user/subscriptions/:owner/:repo", 
        .key = "/user/subscriptions/owner/repo", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":owner",
                    (uint8_t*)"owner"
                },
                {
                    (uint8_t*)":repo",
                    (uint8_t*)"repo"
                }
            }
        }
    },
    { 
        .path = "/user/teams", 
        .key = "/user/teams", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/users/", 
        .key = "/users/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/users/:user/", 
        .key = "/users/user/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/events/", 
        .key = "/users/user/events/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/events/orgs/:org", 
        .key = "/users/user/events/orgs/org", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                },
                {
                    (uint8_t*)":org",
                    (uint8_t*)"org"
                }
            }
        }
    },
    { 
        .path = "/users/:user/events/public", 
        .key = "/users/user/events/public", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/followers", 
        .key = "/users/user/followers", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/following/", 
        .key = "/users/user/following/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/following/:target_user", 
        .key = "/users/user/following/target_user", 
        { 
            .nitems = 2,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                },
                {
                    (uint8_t*)":target_user",
                    (uint8_t*)"target_user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/gists", 
        .key = "/users/user/gists", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/keys", 
        .key = "/users/user/keys", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/orgs", 
        .key = "/users/user/orgs", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/received_events/", 
        .key = "/users/user/received_events/", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/received_events/public", 
        .key = "/users/user/received_events/public", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/repos", 
        .key = "/users/user/repos", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/starred", 
        .key = "/users/user/starred", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    },
    { 
        .path = "/users/:user/subscriptions", 
        .key = "/users/user/subscriptions", 
        { 
            .nitems = 1,
            .items = (usher_glob_item_t[]){
                {
                    (uint8_t*)":user",
                    (uint8_t*)"user"
                }
            }
        }
    }
};
static const testdata_t STATIC_KEYS[157] = {
    { 
        .path = "/", 
        .key = "/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/Makefile", 
        .key = "/Makefile", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/", 
        .key = "/articles/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/go_command.html", 
        .key = "/articles/go_command.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/index.html", 
        .key = "/articles/index.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/", 
        .key = "/articles/wiki/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/Makefile", 
        .key = "/articles/wiki/Makefile", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/edit.html", 
        .key = "/articles/wiki/edit.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/final-noclosure.go", 
        .key = "/articles/wiki/final-noclosure.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/final-noerror.go", 
        .key = "/articles/wiki/final-noerror.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/final-parsetemplate.go", 
        .key = "/articles/wiki/final-parsetemplate.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/final-template.go", 
        .key = "/articles/wiki/final-template.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/final.go", 
        .key = "/articles/wiki/final.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/get.go", 
        .key = "/articles/wiki/get.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/http-sample.go", 
        .key = "/articles/wiki/http-sample.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/index.html", 
        .key = "/articles/wiki/index.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/notemplate.go", 
        .key = "/articles/wiki/notemplate.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/part1-noerror.go", 
        .key = "/articles/wiki/part1-noerror.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/part1.go", 
        .key = "/articles/wiki/part1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/part2.go", 
        .key = "/articles/wiki/part2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/part3-errorhandling.go", 
        .key = "/articles/wiki/part3-errorhandling.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/part3.go", 
        .key = "/articles/wiki/part3.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/test.bash", 
        .key = "/articles/wiki/test.bash", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/test_Test.txt.good", 
        .key = "/articles/wiki/test_Test.txt.good", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/test_edit.good", 
        .key = "/articles/wiki/test_edit.good", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/test_view.good", 
        .key = "/articles/wiki/test_view.good", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/articles/wiki/view.html", 
        .key = "/articles/wiki/view.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/cmd.html", 
        .key = "/cmd.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/code.html", 
        .key = "/code.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/", 
        .key = "/codewalk/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/codewalk.css", 
        .key = "/codewalk/codewalk.css", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/codewalk.js", 
        .key = "/codewalk/codewalk.js", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/codewalk.xml", 
        .key = "/codewalk/codewalk.xml", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/functions.xml", 
        .key = "/codewalk/functions.xml", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/markov.go", 
        .key = "/codewalk/markov.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/markov.xml", 
        .key = "/codewalk/markov.xml", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/pig.go", 
        .key = "/codewalk/pig.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/popout.png", 
        .key = "/codewalk/popout.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/run", 
        .key = "/codewalk/run", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/sharemem.xml", 
        .key = "/codewalk/sharemem.xml", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/codewalk/urlpoll.go", 
        .key = "/codewalk/urlpoll.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/contrib.html", 
        .key = "/contrib.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/contribute.html", 
        .key = "/contribute.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/debugging_with_gdb.html", 
        .key = "/debugging_with_gdb.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/devel/", 
        .key = "/devel/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/devel/release.html", 
        .key = "/devel/release.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/devel/weekly.html", 
        .key = "/devel/weekly.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/docs.html", 
        .key = "/docs.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/effective_go.html", 
        .key = "/effective_go.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/files.log", 
        .key = "/files.log", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gccgo_contribute.html", 
        .key = "/gccgo_contribute.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gccgo_install.html", 
        .key = "/gccgo_install.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go-logo-black.png", 
        .key = "/go-logo-black.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go-logo-blue.png", 
        .key = "/go-logo-blue.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go-logo-white.png", 
        .key = "/go-logo-white.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go1.1.html", 
        .key = "/go1.1.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go1.2.html", 
        .key = "/go1.2.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go1.html", 
        .key = "/go1.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go1compat.html", 
        .key = "/go1compat.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go_faq.html", 
        .key = "/go_faq.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go_mem.html", 
        .key = "/go_mem.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/go_spec.html", 
        .key = "/go_spec.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/", 
        .key = "/gopher/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/appenginegopher.jpg", 
        .key = "/gopher/appenginegopher.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/appenginegophercolor.jpg", 
        .key = "/gopher/appenginegophercolor.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/appenginelogo.gif", 
        .key = "/gopher/appenginelogo.gif", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/bumper.png", 
        .key = "/gopher/bumper.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/bumper192x108.png", 
        .key = "/gopher/bumper192x108.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/bumper320x180.png", 
        .key = "/gopher/bumper320x180.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/bumper480x270.png", 
        .key = "/gopher/bumper480x270.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/bumper640x360.png", 
        .key = "/gopher/bumper640x360.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/doc.png", 
        .key = "/gopher/doc.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/frontpage.png", 
        .key = "/gopher/frontpage.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/gopherbw.png", 
        .key = "/gopher/gopherbw.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/gophercolor.png", 
        .key = "/gopher/gophercolor.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/gophercolor16x16.png", 
        .key = "/gopher/gophercolor16x16.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/help.png", 
        .key = "/gopher/help.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/", 
        .key = "/gopher/pencil/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gopherhat.jpg", 
        .key = "/gopher/pencil/gopherhat.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gopherhelmet.jpg", 
        .key = "/gopher/pencil/gopherhelmet.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gophermega.jpg", 
        .key = "/gopher/pencil/gophermega.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gopherrunning.jpg", 
        .key = "/gopher/pencil/gopherrunning.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gopherswim.jpg", 
        .key = "/gopher/pencil/gopherswim.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pencil/gopherswrench.jpg", 
        .key = "/gopher/pencil/gopherswrench.jpg", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/pkg.png", 
        .key = "/gopher/pkg.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/project.png", 
        .key = "/gopher/project.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/ref.png", 
        .key = "/gopher/ref.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/run.png", 
        .key = "/gopher/run.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/gopher/talks.png", 
        .key = "/gopher/talks.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/help.html", 
        .key = "/help.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/ie.css", 
        .key = "/ie.css", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/install-source.html", 
        .key = "/install-source.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/install.html", 
        .key = "/install.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/logo-153x55.png", 
        .key = "/logo-153x55.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/", 
        .key = "/play/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/fib.go", 
        .key = "/play/fib.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/hello.go", 
        .key = "/play/hello.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/life.go", 
        .key = "/play/life.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/peano.go", 
        .key = "/play/peano.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/pi.go", 
        .key = "/play/pi.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/sieve.go", 
        .key = "/play/sieve.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/solitaire.go", 
        .key = "/play/solitaire.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/play/tree.go", 
        .key = "/play/tree.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/", 
        .key = "/progs/", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/cgo1.go", 
        .key = "/progs/cgo1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/cgo2.go", 
        .key = "/progs/cgo2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/cgo3.go", 
        .key = "/progs/cgo3.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/cgo4.go", 
        .key = "/progs/cgo4.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/defer.go", 
        .key = "/progs/defer.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/defer.out", 
        .key = "/progs/defer.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/defer2.go", 
        .key = "/progs/defer2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/defer2.out", 
        .key = "/progs/defer2.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_bytesize.go", 
        .key = "/progs/eff_bytesize.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_bytesize.out", 
        .key = "/progs/eff_bytesize.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_qr.go", 
        .key = "/progs/eff_qr.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_sequence.go", 
        .key = "/progs/eff_sequence.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_sequence.out", 
        .key = "/progs/eff_sequence.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_unused1.go", 
        .key = "/progs/eff_unused1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/eff_unused2.go", 
        .key = "/progs/eff_unused2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/error.go", 
        .key = "/progs/error.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/error2.go", 
        .key = "/progs/error2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/error3.go", 
        .key = "/progs/error3.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/error4.go", 
        .key = "/progs/error4.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/go1.go", 
        .key = "/progs/go1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/gobs1.go", 
        .key = "/progs/gobs1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/gobs2.go", 
        .key = "/progs/gobs2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_draw.go", 
        .key = "/progs/image_draw.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package1.go", 
        .key = "/progs/image_package1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package1.out", 
        .key = "/progs/image_package1.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package2.go", 
        .key = "/progs/image_package2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package2.out", 
        .key = "/progs/image_package2.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package3.go", 
        .key = "/progs/image_package3.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package3.out", 
        .key = "/progs/image_package3.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package4.go", 
        .key = "/progs/image_package4.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package4.out", 
        .key = "/progs/image_package4.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package5.go", 
        .key = "/progs/image_package5.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package5.out", 
        .key = "/progs/image_package5.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package6.go", 
        .key = "/progs/image_package6.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/image_package6.out", 
        .key = "/progs/image_package6.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/interface.go", 
        .key = "/progs/interface.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/interface2.go", 
        .key = "/progs/interface2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/interface2.out", 
        .key = "/progs/interface2.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json1.go", 
        .key = "/progs/json1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json2.go", 
        .key = "/progs/json2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json2.out", 
        .key = "/progs/json2.out", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json3.go", 
        .key = "/progs/json3.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json4.go", 
        .key = "/progs/json4.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/json5.go", 
        .key = "/progs/json5.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/run", 
        .key = "/progs/run", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/slices.go", 
        .key = "/progs/slices.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/timeout1.go", 
        .key = "/progs/timeout1.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/timeout2.go", 
        .key = "/progs/timeout2.go", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/progs/update.bash", 
        .key = "/progs/update.bash", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/root.html", 
        .key = "/root.html", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/share.png", 
        .key = "/share.png", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/sieve.gif", 
        .key = "/sieve.gif", 
        { 
            .nitems = 0,
        }
    },
    { 
        .path = "/tos.html", 
        .key = "/tos.html", 
        { 
            .nitems = 0,
        }
    }
};


#endif
