//
//  SUAppcast.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/12/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUAPPCAST_H
#define SUAPPCAST_H

@class RSS, SUAppcastItem;
@interface SUAppcast : NSObject {
	NSArray *items;
	NSString *userAgentString;
	id delegate;
}

- (void)fetchAppcastFromURL:(NSURL *)url;
- (void)setDelegate:delegate;
- (void)setUserAgentString:(NSString *)userAgentString;

- (SUAppcastItem *)newestItem;
- (NSArray *)items;

@end

@interface NSObject (SUAppcastDelegate)
- (void)appcastDidFinishLoading:(SUAppcast *)appcast;
- (void)appcast:(SUAppcast *)appcast failedToLoadWithError:(NSError *)error;
@end

#endif
