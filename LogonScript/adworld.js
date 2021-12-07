// ==UserScript==
// @name              攻防世界签到
// @namespace         https://soulsign.inu1255.cn?account=Virtual-Y-Monster
// @version           1.0.0
// @author            Virtual-Y-Monster
// @loginURL          https://adworld.xctf.org.cn/login
// @updateURL         https://soulsign.inu1255.cn/script/Virtual-Y-Monster/攻防世界签到
// @expire            900000
// @domain            adworld.xctf.org.cn
// ==/UserScript==

exports.run = async function (param) {
    try {
        var {
            data
        } = await axios.get('https://adworld.xctf.org.cn/api/personal/daily_checkin');
        if (data.success) {
            return '奖励' + data.coin + '金币';
        } else if (/user_checked_in/.test(data.message)) {
            return '签过了';
        }
    } catch (err) {
        throw '未登录';
    }
};

exports.check = async function (param) {
    try {
        var {
            data
        } = await axios.get('https://adworld.xctf.org.cn/api/personal/daily_checkin');
        return true;
    } catch (err) {
        return false;
    }
};