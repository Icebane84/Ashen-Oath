// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionProtectiveActionResolver.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompanionProtectiveActionResolved, FName, CompanionID);

/**
 * UAshenCompanionProtectiveActionResolver
 * Combat component resolving body-blocking, shield throws, and healing spell intercepts as protective actions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionProtectiveActionResolver : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionProtectiveActionResolver();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnCompanionProtectiveActionResolved OnProtectiveActionResolved;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void ResolveProtectiveAction(FName CompanionID, FString ActionType);
};
