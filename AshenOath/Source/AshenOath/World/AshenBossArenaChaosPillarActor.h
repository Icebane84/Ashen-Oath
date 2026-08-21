// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossArenaChaosPillarActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenBossArenaChaosPillarActor
 * 
 * Destructible structural pillar actor supporting cutting-plane planar slicing
 * and debris generation during boss Phase 2 transitions.
 */
UCLASS()
class ASHENOATH_API AAshenBossArenaChaosPillarActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenBossArenaChaosPillarActor();

	virtual void BeginPlay() override;

	/** Sunders the pillar into physical rubble */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Chaos")
	void FracturePillar(const FVector& ImpactPoint);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Chaos")
	bool IsSundered() const { return bIsSundered; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PillarMesh;

private:
	bool bIsSundered = false;
};
