// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenOathBreachConsequenceHandler.generated.h"

/**
 * UAshenOathBreachConsequenceHandler
 * Combat component applying 25.0 mental damage, generating 0.35 imprint delta, dimming Oathbringer emissives, and dropping pitch by -50 cents.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathBreachConsequenceHandler : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathBreachConsequenceHandler();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void ExecuteBreachConsequenceCascade(const FOathRecord& BreachedOath);
};
