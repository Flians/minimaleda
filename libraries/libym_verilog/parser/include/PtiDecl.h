#ifndef LIBYM_VERILOG_PARSER_INCLUDE_PTIDECL_H
#define LIBYM_VERILOG_PARSER_INCLUDE_PTIDECL_H

/// @file libym_verilog/parser/include/PtiDecl.h
/// @brief 宣言要素関係の部品クラスのヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// $Id: PtiDecl.h 2507 2009-10-17 16:24:02Z matsunaga $
///
/// Copyright (C) 2005-2010 Yusuke Matsunaga
/// All rights reserved.


#include "ym_verilog/pt/PtPort.h"
#include "ym_verilog/pt/PtDecl.h"
#include "PtiFwd.h"


BEGIN_NAMESPACE_YM_VERILOG

//////////////////////////////////////////////////////////////////////
/// @class PtiPort PtiMiodule.h "PtiModule.h"
/// @brief port を表すクラス
//////////////////////////////////////////////////////////////////////
class PtiPort :
  public PtPort
{
public:
  //////////////////////////////////////////////////////////////////////
  // 設定用の関数
  //////////////////////////////////////////////////////////////////////

  /// @brief portref を得る．
  virtual
  PtiPortRef*
  _portref(ymuint32 pos) = 0;
  
};


//////////////////////////////////////////////////////////////////////
/// @class PtiPortRef PtiModule.h "PtiModule.h"
/// @brief port reference を表すクラス
//////////////////////////////////////////////////////////////////////
class PtiPortRef :
  public PtPortRef
{
public:

  /// @brief コンストラクタ
  PtiPortRef();
  
  /// @brief デストラクタ
  ~PtiPortRef();

  
public:
  //////////////////////////////////////////////////////////////////////
  // PtPortRef の仮想関数
  //////////////////////////////////////////////////////////////////////

  /// @brief 方向を得る．
  virtual
  tVpiDirection
  dir() const;


public:
  //////////////////////////////////////////////////////////////////////
  // 設定用の関数
  //////////////////////////////////////////////////////////////////////

  /// @brief 方向をセットする．
  void
  set_dir(tVpiDirection dir);

  
private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // 方向
  tVpiDirection mDir;

};


//////////////////////////////////////////////////////////////////////
/// @class PtiIOHead PtiDecl.h "PtiDecl.h"
/// @brief IO宣言のヘッダを表すクラス
//////////////////////////////////////////////////////////////////////
class PtiIOHead :
  public PtIOHead
{
public:
  //////////////////////////////////////////////////////////////////////
  // PtiIOHead の継承クラスが実装する仮想関数
  //////////////////////////////////////////////////////////////////////

  /// @brief 要素リストの設定
  /// @param[in] elem_array 要素の配列
  virtual
  void
  set_elem(PtIOItemArray elem_array) = 0;

};


//////////////////////////////////////////////////////////////////////
/// @class PtiDeclHead PtiDecl.h "PtiDecl.h"
/// @brief 宣言要素のヘッダの基底クラス
//////////////////////////////////////////////////////////////////////
class PtiDeclHead :
  public PtDeclHead
{
public:
  //////////////////////////////////////////////////////////////////////
  // PtiDeclHead の継承クラスが実装する仮想関数
  //////////////////////////////////////////////////////////////////////

  /// @brief 要素リストの設定
  /// @param[in] elem_array 要素の配列
  virtual
  void
  set_elem(PtDeclItemArray elem_array) = 0;
  
};

END_NAMESPACE_YM_VERILOG

#endif // LIBYM_VERILOG_PARSER_INCLUDE_PTIDECL_H
