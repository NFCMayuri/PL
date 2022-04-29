git filter-branch -f --env-filter "GIT_COMMITTER_NAME=DataEraser; GIT_COMMITTER_EMAIL=MayuriNFC@outlook.com;"
git filter-branch -f --env-filter "GIT_AUTHOR_NAME=DataEraser; GIT_AUTHOR_EMAIL=MayuriNFC@outlook.com; "
git filter-branch -f --env-filter "GIT_COMMITTER_NAME=DataEraser; "

git filter-branch -f --env-filter "if [ $GIT_COMMITTER_NAME == ‘CommitName’ ]; then GIT_COMMITTER_NAME=‘Demo’; fi "

git filter-branch -f --env-filter "if [ $GIT_AUTHOR_NAME == ‘AuthName’ ]; then GIT_AUTHOR_NAME=‘Demo’; fi "

git filter-branch -f --env-filter "if [ $GIT_COMMITTER_EMAIL == ‘CommitEmail’ ]; then GIT_COMMITTER_EMAIL=‘Demo’; fi "

git filter-branch -f --env-filter "if [ $GIT_AUTHOR_EMAIL == ‘AuthEmail’ ]; then GIT_AUTHOR_EMAIL=‘Demo’; fi "
