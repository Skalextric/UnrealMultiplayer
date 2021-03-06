// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

class UWidget;
class UEditableTextBox;
class UButton;
class UWidgetSwitcher;
class UPanelWidget;
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	UMainMenu(const FObjectInitializer & ObjectInitializer);
	
	void SetServerList(TArray<FString> ServerList);

	void SelectIndex(int32 Index);

protected:

	virtual bool Initialize() override;

private:

	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelJoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	UButton* AcceptJoinButton;

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* ServerList;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void CancelJoinMenu();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void QuitGame();

	TSubclassOf<UUserWidget> RowServerClass;

	TOptional<int32> SelectedIndex;


	
};
