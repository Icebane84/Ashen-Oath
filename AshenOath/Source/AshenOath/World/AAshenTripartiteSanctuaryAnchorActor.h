// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AAshenTripartiteSanctuaryAnchorActor.generated.h"

class USphereComponent;

/**
 * AAshenTripartiteSanctuaryAnchorActor
 * 
 * World anchor volume marking contemplative silence exploration sectors or campfire restoration nodes.
 */
UCLASS()
class ASHENOATH_API AAshenTripartiteSanctuaryAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenTripartiteSanctuaryAnchorActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Tripartite")
	ETripartiteBehaviorMode GetDesignatedBehaviorMode() const { return DesignatedMode; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SanctuaryBounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Tripartite")
	ETripartiteBehaviorMode DesignatedMode = ETripartiteBehaviorMode::ContemplativeSilence;
};
