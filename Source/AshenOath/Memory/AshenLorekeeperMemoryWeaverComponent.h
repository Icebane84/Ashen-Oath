// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLorekeeperMemoryWeaverComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryWeaveCompletedSignature, FName, MemoryID, float, ClarityScore);

/**
 * UAshenLorekeeperMemoryWeaverComponent
 *
 * Component driving Serafina's memory weaving & soul state decryption.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLorekeeperMemoryWeaverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenLorekeeperMemoryWeaverComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryWeaver")
	bool WeaveMemoryImprint(FName MemoryID, float EncryptedDepth);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryWeaver|Events")
	FOnMemoryWeaveCompletedSignature OnMemoryWeaveCompleted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryWeaver")
	int32 TotalMemoriesWeaved = 0;
};
