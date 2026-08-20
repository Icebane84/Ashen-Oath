// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenParchmentMarginaliaEvaluatorComponent.generated.h"

/**
 * UAshenParchmentMarginaliaEvaluatorComponent
 * Generates companion margin annotations (Garrett's alchemical sketches vs Serafina's soul reflections) based on FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParchmentMarginaliaEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenParchmentMarginaliaEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	FString ActiveMarginAnnotation;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	void GenerateMarginalia(float TrustScalar, float CorruptionScalar, bool bNearCampfire);
};
