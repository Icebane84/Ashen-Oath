// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRootGnarlTerrainClearanceActor.generated.h"

/**
 * AAshenRootGnarlTerrainClearanceActor
 * In-world actor removing entropic root cages and opening blocked traversal paths upon Root-Gnarl finisher.
 */
UCLASS()
class ASHENOATH_API AAshenRootGnarlTerrainClearanceActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenRootGnarlTerrainClearanceActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Root Gnarl")
	bool bIsPathCleared = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Root Gnarl")
	void ClearRootBlockade();
};
