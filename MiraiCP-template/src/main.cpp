// MiraiCP依赖文件(只需要引入这一个)
#include <MiraiCP.hpp>
using namespace MiraiCP;

const PluginConfig CPPPlugin::config{
    "640992021",          // 插件id，如果和其他插件id重复将会被拒绝加载！
    "tde",                // 插件名称
    "1.0",                // 插件版本
    "tom",                // 插件作者
    "Plugin description", // 可选：插件描述
    "Publish time"        // 可选：日期
};

// 插件实例
class PluginMain : public CPPPlugin
{
public:
  // 配置插件信息
  PluginMain() : CPPPlugin() {}
  ~PluginMain() override = default; // override关键字是为了防止内存泄漏

  // 入口函数。插件初始化时会被调用一次，请在此处注册监听
  void onEnable() override
  {
    /*插件启动时执行一次*/
    Event::registerEvent<PrivateMessageEvent>([](PrivateMessageEvent e)
                                              {
                                                  Friend tom = Friend(783371620, 640992021);

                                                tom.sendMessage(e.message);
                                                return; });

    Event::registerEvent<GroupMessageEvent>([](GroupMessageEvent e)

                                            {
                                              Friend dc = Friend(1924645279, 640992021);
                                              Friend tom = Friend(783371620, 640992021);
                                              dc.sendMessage(e.message);
                                              tom.sendMessage(e.message);
                                              return; });
  }

  // 退出函数。请在这里结束掉所有子线程，否则可能会导致程序崩溃
  void onDisable() override
  {
    /*插件结束前执行*/
  }
};

// 创建当前插件实例。请不要进行其他操作，
// 初始化请在onEnable中进行
void MiraiCP::enrollPlugin()
{
  MiraiCP::enrollPlugin<PluginMain>();
}
