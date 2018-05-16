/*比特币中交易transactions是放置在块block中的，
每一个tx可以看作一个叶子节点，
对这样一个tx的序列计算hash（每2个一组)并构建merkle树，来简化校验块的一致性。*/

uint256 CBlock::BuildMerkleTree() const  
{  
    vMerkleTree.clear();  
    BOOST_FOREACH(const CTransaction& tx, vtx)  
        vMerkleTree.push_back(tx.GetHash());  
    int j = 0;  
    for (int nSize = vtx.size(); nSize > 1; nSize = (nSize + 1) / 2)  
    {  
        for (int i = 0; i < nSize; i += 2)  
        {  
            int i2 = std::min(i+1, nSize-1);  
            vMerkleTree.push_back(Hash(BEGIN(vMerkleTree[j+i]),  END(vMerkleTree[j+i]),  
                                       BEGIN(vMerkleTree[j+i2]), END(vMerkleTree[j+i2])));  
        }  
        j += nSize;  
    }  
    return (vMerkleTree.empty() ? 0 : vMerkleTree.back());  
}  

/*比特币的Hash实现是双重sha256sum (即 Double SHA256)*/
/** Compute the 256-bit hash of the concatenation of two objects. */  
template<typename T1, typename T2>  
inline uint256 Hash(const T1 p1begin, const T1 p1end,  
                    const T2 p2begin, const T2 p2end) {  
    static const unsigned char pblank[1] = {};  
    uint256 result;  
    CHash256().Write(p1begin == p1end ? pblank : (const unsigned char*)&p1begin[0], (p1end - p1begin) * sizeof(p1begin[0]))  
              .Write(p2begin == p2end ? pblank : (const unsigned char*)&p2begin[0], (p2end - p2begin) * sizeof(p2begin[0]))  
              .Finalize((unsigned char*)&result);  
    return result;  
}  

/** A hasher class for Bitcoin's 256-bit hash (double SHA-256). */  
class CHash256 {  
private:  
    CSHA256 sha;  
public:  
    static const size_t OUTPUT_SIZE = CSHA256::OUTPUT_SIZE;  
  
    void Finalize(unsigned char hash[OUTPUT_SIZE]) {  
        unsigned char buf[sha.OUTPUT_SIZE];  
        sha.Finalize(buf);  
        sha.Reset().Write(buf, sha.OUTPUT_SIZE).Finalize(hash);  
    }  
  
    CHash256& Write(const unsigned char *data, size_t len) {  
        sha.Write(data, len);  
        return *this;  
    }  
  
    CHash256& Reset() {  
        sha.Reset();  
        return *this;  
    }  
}; 