class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        
        int cx1 = max(ax1,bx1);
        int cy1 = max(ay1,by1);
        
        int cx2 = min(ax2,bx2);
        int cy2 = min(by2,ay2);
        int area3 = 0;
        
        if ( (cx2-cx1) > 0 && (cy2-cy1) > 0){
            
             area3 = (cy2-cy1) * (cx2-cx1);
        }
        
        int finalarea = area1+ area2 - area3;
        
        
        return finalarea;
        
    }
};