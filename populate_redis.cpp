#include "redcli.hpp"
#include "utils.hpp"
#include "constant.hpp"
#include <cstdlib>

void fill_random_embedding(std::vector<float>& v);

int main(int argc, char *argv[])
{
    utils::Config config(argv[1]);
    config.update(REDIS_HOST, "127.0.0.1");
    RedisClient cli(config);
    std::vector<std::string> keys({"chilao", "baichi", "shabi", "xiaolv", "wuliao", "shanghai", "wenti"});
    for (auto s: keys)
    {
        std::vector<float> tmp(cli.get_embedding_size());
        fill_random_embedding(tmp);
        cli.put_list(s, tmp);
    }
}

void fill_random_embedding(std::vector<float>& v) 
{
    for (int i = 0; i < v.size(); i++){
        v[i] = (float)rand() / RAND_MAX;
    }
}
