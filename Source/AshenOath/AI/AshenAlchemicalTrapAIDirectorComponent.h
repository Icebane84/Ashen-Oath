// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenAlchemicalTrapAIDirectorComponent.generated.h"

/**
 * UAshenAlchemicalTrapAIDirectorComponent
 * AI Director scanning encounter choke points and commanding Garrett to plant caltrops and tripwires proactively.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalTrapAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalTrapAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void DirectProactiveTrapPlacement(FVector ChokePointLocation);
};
