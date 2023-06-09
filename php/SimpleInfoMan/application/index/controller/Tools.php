<?php
namespace app\index\controller;

use think\Db;
use think\Request;

class Tools extends \think\Controller
{
    //todo:数据库函数鉴权
    public function selectDB()
    {
        $data = input();
        $result = Db::table("info");
        foreach ($data as $key => $value) {
            $result = $result->where($key, $value);
            switch ($key) {
                case "order": {
                        $result = $result->order($data["order"]);
                        break;
                    }
                default: {
                        $result = $result->where($key, $value);
                        break;
                    }
            }
        }
        $result = $result->select();
        return json(["code" => 1, "data" => $result]);
    }
    public function deleteDB()
    {
        $result = Db::table("info")->where("id", input('id'))->delete();
        if (!$result)
            return json(["code" => 0, "data" => $result]);
        return json(["code" => 1, "data" => $result]);
    }
    public function insertDB()
    {
        $data = input();
        $result = Db::table("info")->insert($data);
        if (empty($result))
            return json(["code" => 0, "data" => $result]);
        return json(["code" => 1, "data" => $result]);
    }
    public function updateDB()
    {
        $data = input();
        $result = Db::table("info")->where("id", $data["id"])->update($data);
        if (empty($result))
            return json(["code" => 0, "data" => $result]);
        return json(["code" => 1, "data" => $result]);
    }
    public function register()
    {
        $data = input();
        $result = Db::table("users")->insert($data);
        if (empty($result))
            return json(["code" => 0, "data" => $result]);
        return json(["code" => 1, "data" => $result]);
    }
    public function login()
    {
        $data = input();

        $result = Db::table("users")->where("username", $data['username']);
        if (!$result->select())
            return json(["code" => 0, "data" => "username does not found"]);

        $result = $result->where("password", $data['password']);
        if (!$result->select())
            return json(["code" => 0, "data" => "password does not match"]);

        $random = md5(uniqid(rand(), true));
        // todo: 过期时间服务器判断
        $expiration_time = strtotime("+1 hour");
        $expiration_time = date('Y-m-d H:i:s', $expiration_time);
        $data = [
            "username" => $data["username"],
            "token" => $random,
            "expiration_time" => $expiration_time
        ];
        Db::table("tokens")->insert($data);
        return json(["code" => 1, "data" => ["token" => $random, "expiration_time" => $expiration_time]]);
    }
}