// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenLivingOathRegistrySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivingOathSworn, const FOathRecord&, Oath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivingOathFulfilled, const FOathRecord&, Oath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivingOathBreached, const FOathRecord&, Oath);

/**
 * UAshenLivingOathRegistrySubsystem
 * World Subsystem holding authoritative TArray<FOathRecord> for the living oath engine; handles SwearOath(), FulfillOath(), and BreachOath().
 */
UCLASS()
class ASHENOATH_API UAshenLivingOathRegistrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Living Oath")
	FOnLivingOathSworn OnLivingOathSworn;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Living Oath")
	FOnLivingOathFulfilled OnLivingOathFulfilled;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Living Oath")
	FOnLivingOathBreached OnLivingOathBreached;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Living Oath")
	TArray<FOathRecord> ActiveOathRegistry;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Living Oath")
	float ActiveOathBurden = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	bool SwearOath(FName OathID, FText Description);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	bool FulfillOath(FName OathID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	bool BreachOath(FName OathID);
};
