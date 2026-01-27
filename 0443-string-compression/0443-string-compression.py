class Solution:
    def compress(self, chars: List[str]) -> int:
        chars1=[]
        n=len(chars)
        i=0
        if n<2:
            return n
        ch=chars[0]
        count=1
       
        while i<n-1:
            if chars[i]!=chars[i+1]:
                chars1.append(str(ch))
                ch=chars[i+1]
                if count>1:
                    s=list(str(count))
                    chars1.extend(s)
                    count=1
            else:
                count+=1
            i+=1
        chars1.append(str(ch))
        if count>1:
            s=list(str(count))
            chars1.extend(s)
        chars[:]=chars1
        return len(chars)
        
        
            
            
                
                    



        
        