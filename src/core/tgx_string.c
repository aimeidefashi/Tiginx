#include "tgx_string.h"
#include "tgx_alloc.h"

/*
 * @desc : 将传统C语言字符串转换为tgx字符串
 */
tgx_string_t * to_tgx_string( char * string ) {
  tgx_string_t * tgx_string_tp;  
  tgx_string_tp = ( tgx_string_t * )tgx_alloc( sizeof( tgx_string_t ) ); 
  tgx_string_tp->str    = string;
  tgx_string_tp->length = strlen( string );
  return tgx_string_tp; 
}

/*
 * @desc : 比较两个字符串
 */
int tgx_strcmp( const tgx_string_t * dest, const tgx_string_t * src ) {
  return strcmp( dest->str, src->str );   
}

/*
 * @desc : 返回tgx-string字符串长度
 */
size_t tgx_strlen( const tgx_string_t * tgx_string_t ) {
  return tgx_string_t->length;
}

// 拼接字符串
void tgx_strcat( tgx_string_t * dest, tgx_string_t * src ) {
  // 保存原来tgx字符串struct中原来的字符串指针
  char * _temp = dest->str; 
  // 申请内存
  char * temp = ( char * )tgx_alloc( sizeof( dest->str ) + sizeof( src->str ) );  
  bzero( temp, sizeof( temp ) );
  strcpy( temp, dest->str );
  strcpy( temp, src->str );
  // 将指针指向tgx字符串结构体
  dest->str    = temp;  
  dest->length = strlen( dest->str ) + strlen( src->str );
  // 释放原来内存
  tgx_free( _temp ); 
  tgx_free( src->str ); 
  tgx_free( src );
}
