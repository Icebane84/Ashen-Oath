// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionBarkDissonanceResolver.generated.h"

/**
 * UAshenCompanionBarkDissonanceResolver
 * Resolves conflicting companion dialogue barks during chaotic encounters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionBarkDissonanceResolver : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionBarkDissonanceResolver();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	FName ResolveDominantBark(FName GarrettBark, FName SerafinaBark, float GarrettTrust, float SerafinaTrust);
};
