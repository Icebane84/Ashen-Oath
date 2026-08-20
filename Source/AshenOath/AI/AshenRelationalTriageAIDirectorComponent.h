// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenRelationalTriageAIDirectorComponent.generated.h"

/**
 * UAshenRelationalTriageAIDirectorComponent
 * AI Director adjusting Garrett and Serafina's combat formation spacing and support responsiveness based on the compiled relational stance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalTriageAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRelationalTriageAIDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | AI")
	float CompanionProximitySpacingUnits = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void ApplyRelationalStanceToAI(ECompiledRelationalStance Stance);
};
