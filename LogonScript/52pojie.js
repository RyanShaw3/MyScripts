// ==UserScript==
// @name              吾爱破解
// @namespace         https://soulsign.inu1255.cn?account=Virtual-Y-Monster
// @version           1.0.0
// @author            Virtual-Y-Monster
// @loginURL          https://www.52pojie.cn/member.php?mod=logging&action=login
// @expire            900000
// @domain            www.52pojie.cn
// ==/UserScript==

exports.run = async function (param) {
    let windows = await open("https://www.52pojie.cn/home.php?mod=task&do=apply&id=2");
    setTimeout(function () { windows.close(); }, 5000);
    return '签到成功';
};

exports.check = async function (param) {
    return true;
};