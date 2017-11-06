//
//  main.cpp
//  Trees
//
//  Created by Apoorv on 27/09/17.
//  Copyright © 2017 presonal. All rights reserved.
//

#include <iostream>
#include "SolutionTrees.hpp"
void inorder(TreeNode* root);
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root = new TreeNode(0);
    //    TreeNode *root1;
    TreeNode *n1 = new TreeNode(7);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(9);
    TreeNode *n4 = new TreeNode(0);
    //    TreeNode *n5 = new TreeNode(6);
    //    TreeNode *n6 = new TreeNode(7);
    //    TreeNode *n7 = new TreeNode(9);
    //    TreeNode *n8 = new TreeNode(1);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
//    n8->left = n2;
//    n8->right = n4;
//    n2->right = n5;
//    n2->left = n5;
//    n2->right = n6;
//    n6->left = n7;
//    n6->right = n8;
//    root1 = new TreeNode(10);
//    root1->left = n1;
//    root1->right = n6;
    
//    TreeLinkNode *root = new TreeLinkNode(1);
//    TreeLinkNode *n2 = new TreeLinkNode(2);
//    TreeLinkNode *n3 = new TreeLinkNode(3);
//    TreeLinkNode *n4 = new TreeLinkNode(4);
//    TreeLinkNode *n5 = new TreeLinkNode(5);
//    TreeLinkNode *n6 = new TreeLinkNode(6);
//    TreeLinkNode *n7 = new TreeLinkNode(7);
//    TreeLinkNode *n8 = new TreeLinkNode(8);
//    root->left = n2;
//    root->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;
//
//    connect(root);
    string s = "qghu_eay_nl_dxfi_cvsc_gg_wk_nqdu_wf_fozv_rtk_pr_p_g_rp_rvys_mwcy_y_c_pev_kef_mz_imkk_svw_r_nzk_cxf_tl_gyp_fad_oo_fxz_co_juv_vabo_gpo_ylf_bnpl_vrvi_ya_yeh_q_qrqp_x_j_loov_o_u_wh_s_cb_coks_zkva_xdkn_yj_h_ixjs_nkk_f_ux_zr_bmnm_q_oke_ly_nk_aug_qrcd_iute_ojw_yyz_vs_m_sa_lfvg_b_aaov_zy_nt_kdcp_s_te_j_hdi_co_zc_fw_qi_tv_wvxh";
    vector<string> b = { "zebra", "dog", "duck", "dot"  };//{"zebra", "dog", "duck", "dot"};
    string a = "cool_ice_wifi";
    vector<string> z = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    vector<int> heights = {5, 3, 2, 6, 1, 4};
    vector<int> infronts = {0, 1, 2, 0, 3, 2};
    vector<int>r =  order(heights,infronts);
    for(int s: r)
    {
        cout<< s<<endl;
    }
//    vector<int>inorderv = {1,2,5, 6, 7, 10, 15, 20, 25, 27, 28, 29, 30};
//    vector<int>preorder = {20, 10, 5, 1, 2, 7, 6, 15, 30, 25, 27, 28, 29};
//   TreeNode *r = buildTreeFromInorderPreorder(preorder, inorderv);
//    TreeNode*x =  flattenBinaryTree(r);
//    while (x) {
//        cout << x->val << " ";
//        x = x->right;
//    }
//    BSTIterator i = BSTIterator(r);
//    while (i.hasNext()) cout << i.next() << " ";
    //inorder(r);
//    cout<< endl<<  lca(r, 2, 20);
    //TreeNode *res = invertTree(root);
   // inorder(res);
    //cout<<  minDepth(root);
//    vector<vector<int>> res = zigzagLevelOrder(r);
//    for(vector<int> x: res){
//        for(int y: x){
//        cout << y <<" " ;
//        }
//        cout<<endl;
//    }
    return 0;
}

void inorder(TreeNode* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout<< root->val <<" ";
    inorder(root->right);
}

void preorder(TreeNode* root)
{
    if (!root) {
        return;
    }
    cout<< root->val <<" ";
    inorder(root->left);
    inorder(root->right);
}
