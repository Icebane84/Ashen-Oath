// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherMotionWarpComponent.generated.h"

/**
 * UAshenFinisherMotionWarpComponent
 * Manages spatial target alignment and bone socket attachments between multiple characters during synchronized finishers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherMotionWarpComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherMotionWarpComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Motion Warp")
	bool bIsWarpingActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Motion Warp")
	bool WarpCharacterToTarget(AActor* CharacterActor, FVector TargetLocation, FRotator TargetRotation, float WarpSpeed);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Motion Warp")
	bool SnapHandToPartnerSocket(AActor* AttachingChar, FName SourceSocket, AActor* PartnerChar, FName TargetSocket);
};
