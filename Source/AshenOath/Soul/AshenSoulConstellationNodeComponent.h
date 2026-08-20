// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenSoulConstellationNodeComponent.generated.h"

/**
 * UAshenSoulConstellationNodeComponent
 * Evaluates 3D node distances between Kaelen, Serafina, and Garrett in the soul graph (stretching to 500uu in Martyr stance, contracting to 150uu in Weaver stance).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulConstellationNodeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSoulConstellationNodeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float CompanionNodeDistanceUnits = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void UpdateConstellationDistances(ECompiledRelationalStance Stance);
};
