import requests
import json

id = 882842     # 从个人主页的url中获得
bbs_token = ''  # 从签到时的cookies中获得
sckey = ''      # 用GitHub账号登录server酱后获得
server = '1'    # 1开启server酱通知  0关闭


class Login():
    def __init__(self):
        self.get_url = 'https://passport.kanxue.com/user-public_json-'+str(id)+'.htm'
        self.signin_url = 'https://bbs.pediy.com/user-signin.htm'
        self.info_url = 'https://sc.ftqq.com/'+sckey+'.send'
        self.header = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36'
        }
        self.cookie = {
            'bbs_token': bbs_token
        }
        self.session = requests.Session()

    def get_info(self):
        response = self.session.get(self.get_url, headers=self.header)
        response = json.loads(response.text)
        return response['message']["golds"]

    def sign_in(self):
        response = self.session.post(self.signin_url, cookies=self.cookie)
        response = json.loads(response.text)
        if response['code'] == '-1':
            print('sign in failed')
        else:
            print('sign in success')
        return response

    def send(self):
        sign_info = self.sign_in()
        golds = self.get_info()
        if server == '1':
            if sign_info['code'] == '-1':
                text = '看雪论坛_签到失败'
                desp = str(sign_info['message'])
            else:
                text = '看雪论坛_签到成功'
                desp = '签到奖励雪币'+str(sign_info['message'])+'您现有雪币'+str(golds)
            url = self.info_url+"?text="+text+"&desp="+desp
            requests.get(url)

if __name__ == "__main__":
    login = Login()
    login.send()

