// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryDuelArenaBoundsActor.generated.h"

/**
 * AAshenMemoryDuelArenaBoundsActor
 * Mindscape memory duel circular arena boundary actor restricting exit until combat ends.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryDuelArenaBoundsActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryDuelArenaBoundsActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Arena")
	float ArenaRadius = 1200.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Arena")
	void LockArenaBoundaries();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Arena")
	void UnlockArenaBoundaries();
};
