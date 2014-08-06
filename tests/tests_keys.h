//
//  tests_keys.h
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#ifndef ___LIBUSHER_TESTS_KEYS_H___
#define ___LIBUSHER_TESTS_KEYS_H___


static const char *STATIC_KEYS[] = {
    "/",
    "/Makefile",
    "/articles/",
    "/articles/go_command.html",
    "/articles/index.html",
    "/articles/wiki/",
    "/articles/wiki/Makefile",
    "/articles/wiki/edit.html",
    "/articles/wiki/final-noclosure.go",
    "/articles/wiki/final-noerror.go",
    "/articles/wiki/final-parsetemplate.go",
    "/articles/wiki/final-template.go",
    "/articles/wiki/final.go",
    "/articles/wiki/get.go",
    "/articles/wiki/http-sample.go",
    "/articles/wiki/index.html",
    "/articles/wiki/notemplate.go",
    "/articles/wiki/part1-noerror.go",
    "/articles/wiki/part1.go",
    "/articles/wiki/part2.go",
    "/articles/wiki/part3-errorhandling.go",
    "/articles/wiki/part3.go",
    "/articles/wiki/test.bash",
    "/articles/wiki/test_Test.txt.good",
    "/articles/wiki/test_edit.good",
    "/articles/wiki/test_view.good",
    "/articles/wiki/view.html",
    "/cmd.html",
    "/code.html",
    "/codewalk/",
    "/codewalk/codewalk.css",
    "/codewalk/codewalk.js",
    "/codewalk/codewalk.xml",
    "/codewalk/functions.xml",
    "/codewalk/markov.go",
    "/codewalk/markov.xml",
    "/codewalk/pig.go",
    "/codewalk/popout.png",
    "/codewalk/run",
    "/codewalk/sharemem.xml",
    "/codewalk/urlpoll.go",
    "/contrib.html",
    "/contribute.html",
    "/debugging_with_gdb.html",
    "/devel/",
    "/devel/release.html",
    "/devel/weekly.html",
    "/docs.html",
    "/effective_go.html",
    "/files.log",
    "/gccgo_contribute.html",
    "/gccgo_install.html",
    "/go-logo-black.png",
    "/go-logo-blue.png",
    "/go-logo-white.png",
    "/go1.1.html",
    "/go1.2.html",
    "/go1.html",
    "/go1compat.html",
    "/go_faq.html",
    "/go_mem.html",
    "/go_spec.html",
    "/gopher/",
    "/gopher/appenginegopher.jpg",
    "/gopher/appenginegophercolor.jpg",
    "/gopher/appenginelogo.gif",
    "/gopher/bumper.png",
    "/gopher/bumper192x108.png",
    "/gopher/bumper320x180.png",
    "/gopher/bumper480x270.png",
    "/gopher/bumper640x360.png",
    "/gopher/doc.png",
    "/gopher/frontpage.png",
    "/gopher/gopherbw.png",
    "/gopher/gophercolor.png",
    "/gopher/gophercolor16x16.png",
    "/gopher/help.png",
    "/gopher/pencil/",
    "/gopher/pencil/gopherhat.jpg",
    "/gopher/pencil/gopherhelmet.jpg",
    "/gopher/pencil/gophermega.jpg",
    "/gopher/pencil/gopherrunning.jpg",
    "/gopher/pencil/gopherswim.jpg",
    "/gopher/pencil/gopherswrench.jpg",
    "/gopher/pkg.png",
    "/gopher/project.png",
    "/gopher/ref.png",
    "/gopher/run.png",
    "/gopher/talks.png",
    "/help.html",
    "/ie.css",
    "/install-source.html",
    "/install.html",
    "/logo-153x55.png",
    "/play/",
    "/play/fib.go",
    "/play/hello.go",
    "/play/life.go",
    "/play/peano.go",
    "/play/pi.go",
    "/play/sieve.go",
    "/play/solitaire.go",
    "/play/tree.go",
    "/progs/",
    "/progs/cgo1.go",
    "/progs/cgo2.go",
    "/progs/cgo3.go",
    "/progs/cgo4.go",
    "/progs/defer.go",
    "/progs/defer.out",
    "/progs/defer2.go",
    "/progs/defer2.out",
    "/progs/eff_bytesize.go",
    "/progs/eff_bytesize.out",
    "/progs/eff_qr.go",
    "/progs/eff_sequence.go",
    "/progs/eff_sequence.out",
    "/progs/eff_unused1.go",
    "/progs/eff_unused2.go",
    "/progs/error.go",
    "/progs/error2.go",
    "/progs/error3.go",
    "/progs/error4.go",
    "/progs/go1.go",
    "/progs/gobs1.go",
    "/progs/gobs2.go",
    "/progs/image_draw.go",
    "/progs/image_package1.go",
    "/progs/image_package1.out",
    "/progs/image_package2.go",
    "/progs/image_package2.out",
    "/progs/image_package3.go",
    "/progs/image_package3.out",
    "/progs/image_package4.go",
    "/progs/image_package4.out",
    "/progs/image_package5.go",
    "/progs/image_package5.out",
    "/progs/image_package6.go",
    "/progs/image_package6.out",
    "/progs/interface.go",
    "/progs/interface2.go",
    "/progs/interface2.out",
    "/progs/json1.go",
    "/progs/json2.go",
    "/progs/json2.out",
    "/progs/json3.go",
    "/progs/json4.go",
    "/progs/json5.go",
    "/progs/run",
    "/progs/slices.go",
    "/progs/timeout1.go",
    "/progs/timeout2.go",
    "/progs/update.bash",
    "/root.html",
    "/share.png",
    "/sieve.gif",
    "/tos.html"
};

static const char *GITHUB_API[] = {
    "/applications/:client_id/tokens/:access_token",
    "/authorizations/",
    "/authorizations/:id",
    "/emojis",
    "/events",
    "/feeds",
    "/gists/",
    "/gists/:id/",
    "/gists/:id/star",
    "/gists/public",
    "/gists/starred",
    "/gitignore/templates/",
    "/gitignore/templates/:name",
    "/issues",
    "/legacy/issues/search/:owner/:repository/:state/:keyword",
    "/legacy/repos/search/:keyword",
    "/legacy/user/email/:email",
    "/legacy/user/search/:keyword",
    "/meta",
    "/networks/:owner/:repo/events",
    "/notifications/",
    "/notifications/threads/:id/",
    "/notifications/threads/:id/subscription",
    "/orgs/:org/",
    "/orgs/:org/events",
    "/orgs/:org/issues",
    "/orgs/:org/members/",
    "/orgs/:org/members/:user",
    "/orgs/:org/public_members/",
    "/orgs/:org/public_members/:user",
    "/orgs/:org/repos",
    "/orgs/:org/teams",
    "/rate_limit",
    "/repos/:owner/:repo/",
    "/repos/:owner/:repo/:archive_format/:ref",
    "/repos/:owner/:repo/assignees/",
    "/repos/:owner/:repo/assignees/:assignee",
    "/repos/:owner/:repo/branches/",
    "/repos/:owner/:repo/branches/:branch",
    "/repos/:owner/:repo/collaborators/",
    "/repos/:owner/:repo/collaborators/:user",
    "/repos/:owner/:repo/comments/",
    "/repos/:owner/:repo/comments/:id",
    "/repos/:owner/:repo/commits/",
    "/repos/:owner/:repo/commits/:sha/",
    "/repos/:owner/:repo/commits/:sha/comments",
    "/repos/:owner/:repo/contents/*path",
    "/repos/:owner/:repo/contributors",
    "/repos/:owner/:repo/downloads/",
    "/repos/:owner/:repo/downloads/:id",
    "/repos/:owner/:repo/events",
    "/repos/:owner/:repo/forks",
    "/repos/:owner/:repo/git/blobs/:sha",
    "/repos/:owner/:repo/git/commits/:sha",
    "/repos/:owner/:repo/git/refs",
    "/repos/:owner/:repo/git/refs/*ref",
    "/repos/:owner/:repo/git/tags/:sha",
    "/repos/:owner/:repo/git/trees/:sha",
    "/repos/:owner/:repo/hooks/",
    "/repos/:owner/:repo/hooks/:id",
    "/repos/:owner/:repo/issues/",
    "/repos/:owner/:repo/issues/:number/",
    "/repos/:owner/:repo/issues/:number/comments",
    "/repos/:owner/:repo/issues/:number/events",
    "/repos/:owner/:repo/issues/:number/labels",
    "/repos/:owner/:repo/issues/comments",
    "/repos/:owner/:repo/issues/comments/:id",
    "/repos/:owner/:repo/issues/events",
    "/repos/:owner/:repo/issues/events/:id",
    "/repos/:owner/:repo/keys/",
    "/repos/:owner/:repo/keys/:id",
    "/repos/:owner/:repo/labels/",
    "/repos/:owner/:repo/labels/:name",
    "/repos/:owner/:repo/languages",
    "/repos/:owner/:repo/milestones/",
    "/repos/:owner/:repo/milestones/:number/",
    "/repos/:owner/:repo/milestones/:number/labels",
    "/repos/:owner/:repo/notifications",
    "/repos/:owner/:repo/pulls/",
    "/repos/:owner/:repo/pulls/:number/",
    "/repos/:owner/:repo/pulls/:number/comments",
    "/repos/:owner/:repo/pulls/:number/commits",
    "/repos/:owner/:repo/pulls/:number/files",
    "/repos/:owner/:repo/pulls/:number/merge",
    "/repos/:owner/:repo/pulls/comments",
    "/repos/:owner/:repo/pulls/comments/:number",
    "/repos/:owner/:repo/readme",
    "/repos/:owner/:repo/releases/",
    "/repos/:owner/:repo/releases/:id/",
    "/repos/:owner/:repo/releases/:id/assets",
    "/repos/:owner/:repo/stargazers",
    "/repos/:owner/:repo/stats/code_frequency",
    "/repos/:owner/:repo/stats/commit_activity",
    "/repos/:owner/:repo/stats/contributors",
    "/repos/:owner/:repo/stats/participation",
    "/repos/:owner/:repo/stats/punch_card",
    "/repos/:owner/:repo/statuses/:ref",
    "/repos/:owner/:repo/subscribers",
    "/repos/:owner/:repo/subscription",
    "/repos/:owner/:repo/tags",
    "/repos/:owner/:repo/teams",
    "/repositories",
    "/search/code",
    "/search/issues",
    "/search/repositories",
    "/search/users",
    "/teams/:id/",
    "/teams/:id/members/",
    "/teams/:id/members/:user",
    "/teams/:id/repos/",
    "/teams/:id/repos/:owner/:repo",
    "/user/",
    "/user/emails",
    "/user/followers",
    "/user/following/",
    "/user/following/:user",
    "/user/issues",
    "/user/keys/",
    "/user/keys/:id",
    "/user/orgs",
    "/user/repos",
    "/user/starred/",
    "/user/starred/:owner/:repo",
    "/user/subscriptions/",
    "/user/subscriptions/:owner/:repo",
    "/user/teams",
    "/users/",
    "/users/:user/",
    "/users/:user/events/",
    "/users/:user/events/orgs/:org",
    "/users/:user/events/public",
    "/users/:user/followers",
    "/users/:user/following/",
    "/users/:user/following/:target_user",
    "/users/:user/gists",
    "/users/:user/keys",
    "/users/:user/orgs",
    "/users/:user/received_events/",
    "/users/:user/received_events/public",
    "/users/:user/repos",
    "/users/:user/starred",
    "/users/:user/subscriptions"
};

#endif
