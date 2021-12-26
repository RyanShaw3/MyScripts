// ==UserScript==
// @name              看雪论坛
// @namespace         https://soulsign.inu1255.cn?account=Virtual-Y-Monster
// @version           1.0.0
// @author            Virtual-Y-Monster
// @loginURL          https://passport.kanxue.com/user-login.htm
// @expire            900000
// @domain            bbs.pediy.com
// @domain            passport.kanxue.com
// ==/UserScript==


exports.run = async function (param) {
    var {
        data
    } = await axios.post(
        "https://bbs.pediy.com/user-signin.htm"
    );
    if (data.code == "0" || (data.code == "-1" && data.message == "您今日已签到成功")) {
        return data.message;
    } else {
        throw data.message;
    }
};

exports.check = async function (param) {
    var {
        data
    } = await axios.get(
        "https://passport.kanxue.com/my.htm", {
            maxRedirects: 0
        }
    );
    return !/请登录/.test(data);
};