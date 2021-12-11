import requests
import json

sessdata = ''  # 每次登录后从cookies中获取
sckey = ''     # 用GitHub账号登录server酱后获得
server = '1'   # 1开启server酱通知  0关闭


class Login(object):
    def __init__(self):
        self.get_url = 'https://api.bilibili.com/x/web-interface/nav'
        self.signin_url = 'https://api.live.bilibili.com/sign/doSign'
        self.info_url = 'https://sc.ftqq.com/'+sckey+'.send'
        self.cookie = {
            "SESSDATA": sessdata
        }
        self.session = requests.Session()

    def get_info(self):
        """
        获取用户的个人信息
        """
        response = self.session.get(self.get_url, cookies=self.cookie)
        response = json.loads(response.text)
        info = {}
        if response["code"] == 0:
            print("login success")
            info['uid'] = response['data']['mid']
            info['uname'] = response['data']['uname']
        else:
            print("login failed")
        return info

    def sign_in(self):
        """
        签到函数
        """
        response = self.session.get(self.signin_url, cookies=self.cookie)
        response = json.loads(response.text)
        info = {}
        if response["code"] == 0:
            print("sign in success")
            info = response['data']
        else:
            print("sign in failed")
        return info

    def send(self):
        """
        获取用户信息和签到信息
        调用server酱的api向用户发送微信推送
        """
        user_info = self.get_info()
        sign_info = self.sign_in()
        if server == '1':
            if len(user_info) == 0:
                text = 'bilibili直播_登录失败'
                desp = 'cookie失效请更新'
            elif len(sign_info) == 0:
                text = 'bilibili直播_签到失败'
                desp = '不可重复签到'
            else:
                text = 'bilibili直播_签到成功'
                info = user_info
                info.update(sign_info)
                desp = json.dumps(info, indent=0, ensure_ascii=False)[1:-1]
            url = self.info_url+"?text="+text+"&desp="+desp
            requests.get(url)


if __name__ == "__main__":
    login = Login()
    login.send()
