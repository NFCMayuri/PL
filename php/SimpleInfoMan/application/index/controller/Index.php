<?php
namespace app\index\controller;
use think\Db;

class Index extends \think\Controller
{
    public function index()
    {
        return view();
    }
    public function login()
    {
        return view();
    }

    public function hello($name = 'ThinkPHP5')
    {
        return 'hello,' . $name;
    }
    public function register()
    {
        return view();
    }
    public function info()
    {
        $userList = Db::table("users")->select();
        $this->assign(["userList" => $userList]);
        return $this->fetch("info");
    }
}