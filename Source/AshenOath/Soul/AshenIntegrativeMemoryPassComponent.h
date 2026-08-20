// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenIntegrativeMemoryPassComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIntegrativePassCompletedSignature, FName, MemoryID, FName, AppliedLensTag);

/**
 * UAshenIntegrativeMemoryPassComponent
 *
 * Component executing the Integrative Pass ("What happened?", Grace / Accountability Lenses, stabilizing truth in Memory Palace).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIntegrativeMemoryPassComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenIntegrativeMemoryPassComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|IntegrativePass")
	void ExecuteIntegrativePass(FName MemoryID, FName LensTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|IntegrativePass|Events")
	FOnIntegrativePassCompletedSignature OnIntegrativeCompleted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|IntegrativePass")
	int32 TotalMemoriesIntegrated = 0;
};
