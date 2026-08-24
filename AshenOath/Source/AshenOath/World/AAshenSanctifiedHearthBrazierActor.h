// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AAshenSanctifiedHearthBrazierActor.generated.h"

class USphereComponent;
class UPointLightComponent;

/**
 * AAshenSanctifiedHearthBrazierActor
 * 
 * Ancient stone Hearth Brazier actor in Northern Marches that radiates sanctuary heat when ignited.
 */
UCLASS()
class ASHENOATH_API AAshenSanctifiedHearthBrazierActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctifiedHearthBrazierActor();

	virtual void BeginPlay() override;

	/** Updates flame visuals and warmth radius */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Scenario6|Hearth")
	void SetIgnitionVisuals(float Progress, EHearthSanctuaryState State);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BrazierMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SanctuaryWarmthZone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPointLightComponent* HearthLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario6|Hearth")
	float CurrentIgnitionProgress = 0.0f;
};
