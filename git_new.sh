# !bin/bash/

git init

#git clone git@github.com:littlebee21/HuaQing.git

#add file to push
git checkout -b

#set branch and respos
git branch -M master

# 设置远程仓库，ssh方式的不需要使用密码
# git remote add origin https://github.com/littlebee21/siwei.git
git remote add origin git@github.com:littlebee21/Runway-warning-system-model.git


# 添加对应的内容 然后进行递交
git add .
git commit -m "all commit"



#orgin 是起源的意思 main是分治
git push -u origin master
#git push -u -f origin master
