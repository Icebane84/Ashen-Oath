// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenRetroactiveMarginaliaInscriberComponent.generated.h"

/**
 * UAshenRetroactiveMarginaliaInscriberComponent
 * 
 * Manages secret, unnotified companion annotations inscribed onto historical journal pages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRetroactiveMarginaliaInscriberComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRetroactiveMarginaliaInscriberComponent();

	/** Inscribes a new retroactive marginalia note */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Journal")
	FRetroactiveMarginaliaEntry InscribeMarginalia(
		int32 PageIndex,
		FName Author,
		const FString& Content,
		EMarginaliaInkMedium Medium);

	/** Retrieves all marginalia for a specific page */
	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Journal")
	TArray<FRetroactiveMarginaliaEntry> GetMarginaliaForPage(int32 PageIndex) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Journal")
	int32 GetTotalMarginaliaCount() const { return InscribedEntries.Num(); }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Narrative|Journal")
	TArray<FRetroactiveMarginaliaEntry> InscribedEntries;
};
