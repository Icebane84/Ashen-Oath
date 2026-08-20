// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenTAM001AIDirectorComponent.generated.h"

/**
 * UAshenTAM001AIDirectorComponent
 * AI Director translating TAM-001 consistency scores into companion spacing and proactive combat setup barks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTAM001AIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTAM001AIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	float CalculateCompanionDefensiveSpacing(float ConsistencyScore) const;
};
