// ==UserScript==
// @name              geekhub
// @namespace         https://soulsign.inu1255.cn?account=Virtual-Y-Monster
// @version           1.0.0
// @author            Virtual-Y-Monster
// @loginURL          https://www.geekhub.com/users/sign_in
// @expire            900000
// @domain            www.geekhub.com
// ==/UserScript==

exports.run = async function (param) {
    var { data } = await axios.get('https://www.geekhub.com/settings');
    if (/你需要登录后才能继续/.test(data))
        throw '未登录';
    var { data } = await axios.get('https://www.geekhub.com/checkins');
    if (/今日已签到/.test(data))
        return '今日已签到';
    var windows = await open('https://www.geekhub.com/checkins');
    return '签到成功';
};

exports.check = async function (param) {
    var {
        data
    } = await axios.get('https://www.geekhub.com/settings');
    return !(/你需要登录后才能继续/.test(data));
};
