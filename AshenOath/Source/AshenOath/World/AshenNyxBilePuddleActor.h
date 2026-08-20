// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenNyxBilePuddleActor.generated.h"

/**
 * AAshenNyxBilePuddleActor
 * 3D ground hazard actor left in the soil by falling bile ribbons (-450 Z gravity), slowing enemies and decaying over 8.0s.
 */
UCLASS()
class ASHENOATH_API AAshenNyxBilePuddleActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenNyxBilePuddleActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float PuddleRadius = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float SlowFactor = 0.65f; // -35% speed

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Hazard")
	float RemainingDuration = 8.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hazard")
	bool ApplyPuddleSlow(AActor* TargetActor);
};
